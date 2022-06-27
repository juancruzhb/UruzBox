#include "ReglasLogicas.h"
#include<iostream>
#include<string>
#include "Fecha.h"
#include"AccesoDatos.h"
#include <iomanip>
using namespace std;

AccesoDatos _accesoDatos;

//prototipos
#pragma region Manipulacion de Alumnos

bool confirmarIngreso(Alumno reg);
void mostrarDatosAlumno(Alumno reg);
Alumno solicitarDatosAlumno();

bool ReglasLogicas::existeAlumno(int dni) {

	int reg = _accesoDatos.obtenerRegistroPorDni(dni);
	if (reg < 0) {
		return false;
	}
	return _accesoDatos.leerDeDisco(reg);
}
int ReglasLogicas::ingresarAlumno() {
	bool op = true;
	while (op) {
		Alumno alumno = solicitarDatosAlumno();
		if (confirmarIngreso(alumno)) {
			_accesoDatos.grabarAlumnoEnDisco(alumno);
			return alumno.getDni();
		}
	}
}
bool ReglasLogicas::eliminarAlumno(int dni) {
	Alumno alumno = obtenerAlumno(-1, dni);
	char opcion;
	cout << endl << endl;
	cout << "Uds va a eliminar al siguiente alumno: " << endl << endl << endl;

	mostrarDatosAlumno(alumno);

	cout << endl;
	cout << endl << endl << endl << endl;

	cout << "Desea confirmar la eliminacion? (s/n): ";
	cin >> opcion;
	if (tolower(opcion) == 's') {
		alumno.setActivo(false);
		return _accesoDatos.GuardarEnDisco(alumno, dni);
	}
	else {
		return false;
	}
}

Alumno ReglasLogicas::obtenerAlumno(int reg, int dni) {
	if (dni == 0) {
		//if (_accesoDatos.obtenerAlumno(reg).getActivo()) {
			return _accesoDatos.obtenerAlumno(reg);
		//}
	}
	else {
		return _accesoDatos.obtenerAlumno(_accesoDatos.obtenerRegistroPorDni(dni));
	}
}

int ReglasLogicas::cantidadDeAlumnos(){
	return _accesoDatos.cantidad_registros_alumnos();
}


bool confirmarIngreso(Alumno reg) {
	char opcion;
	cout << endl << endl;
	cout << "Uds ha ingresado los siguientes datos: " << endl<<endl<<endl;

	mostrarDatosAlumno(reg);

	cout << endl;
	cout << endl << endl << endl << endl;

	cout << "Desea confirmar el ingreso? (s/n): ";
	cin >> opcion;
	if (tolower(opcion) == 's') {
		return true;
	}
	else {
		return false;
	}
}
void mostrarDatosAlumno(Alumno reg) {
	cout << left;
	cout << setw(12) << "   DNI";
	cout << setw(15) << "APELLIDO";
	cout << setw(15) << "NOMBRE";
	cout << setw(15) << "FECHA";
	cout << setw(25) << "      EMAIL";
	cout << setw(15) << "CELULAR";
	cout << setw(15) << "SUSCRIPCION" << endl;


	cout << "---------------------------------------------------------------------------------------------" << endl;
	cout << left;
	cout << setw(12) << reg.getDni();
	cout << setw(15) << reg.getApellido();
	cout << setw(15) << reg.getNombre();
	cout << setw(15) << reg.getFechaNac().toString();
	cout << setw(25) << reg.getContacto().getMail();
	cout << setw(15) << reg.getContacto().getCelular();
	cout << setw(15) << reg.getSuscripcionString();

	cout << endl;
	cout << endl << endl << endl << endl;
}
Alumno solicitarDatosAlumno() {
	system("cls");
	int id = _accesoDatos.cantidad_registros_alumnos() + 1;
	int dni, dia, mes, anio, celular, suscripcion;
	string nombre;
	string apellido;
	string mail; 
	cout << "DNI: ";
	cin >> dni;
	cout << "Apellido: ";
	cin >> apellido;
	cout << "Nombre: ";
	cin >> nombre;
	cout << "Dia de nacimiento: ";
	cin >> dia;
	cout << "Mes de nacimiento: ";
	cin >> mes;
	cout << "Anio de nacimiento: ";
	cin >> anio; 
	cout << "Celular: ";
	cin >> celular;
	cout << "E-Mail: ";
	cin >> mail;
	cout << "Suscripcion (1)2 veces por semana 2) 3 veces por semana - 3) Libre): ";
	cin >> suscripcion;
	Contacto contacto(celular,mail);
	Fecha fecha(dia, mes, anio);
	Alumno alumno(id, dni, apellido, nombre,fecha , contacto, suscripcion);
	return alumno;
}
#pragma endregion

#pragma region Manipulacion de Asistencias

bool ReglasLogicas::ingresarAsistenciaPorDni() {
	int id = cantidadDeAsistencias() + 1;
	int dni;
	bool ok;
	cout << "Ingrese el DNI: ";
	cin >> dni;
	if (_accesoDatos.obtenerRegistroPorDni(dni)>=0) {
		Alumno aux = _accesoDatos.obtenerAlumno(_accesoDatos.obtenerRegistroPorDni(dni));
		Asistencia asistencia(id, aux.getId());
		if (_accesoDatos.grabarAsistenciaEnDisco(asistencia)) {
			ok = true;
		}
		else {
			ok = false;
		}
	}
	else {
		ok = false;
	}
	
	return ok;
}
bool ReglasLogicas::ingresarAsistenciaPorApellido() {
	//TODO: discriminar min y mayus. Ver si hay 2 apellidos iguales
	int id = cantidadDeAsistencias() + 1;
	std::string apellido;
	bool ok;
	cout << "Ingrese el Apellido: ";
	cin >> apellido;
	if (_accesoDatos.obtenerRegistroPorApellido(apellido) >= 0) {
		Alumno aux = _accesoDatos.obtenerAlumno(_accesoDatos.obtenerRegistroPorApellido(apellido));
		Asistencia asistencia(id, aux.getId());
		if (_accesoDatos.grabarAsistenciaEnDisco(asistencia)) {
			ok = true;
		}
		else {
			ok = false;
		}
	}
	else {
		ok = false;
	}

	return ok;
}

Asistencia ReglasLogicas::obtenerAsistencia(int reg) {
	return _accesoDatos.obtenerAsistencia(reg);
}
int ReglasLogicas::cantidadDeAsistencias() {
	return _accesoDatos.cantidad_registros_asistencias();
}

#pragma endregion

#pragma region Manipulacion de Pagos

bool ReglasLogicas::ingresarPago(int idAlumno, float importe, Fecha desde, Fecha hasta) {
	Fecha actual;
	Pagos pago;
	pago.setId(_accesoDatos.cantidad_registros_pagos()+1);
	pago.setIdAlumno(idAlumno);
	pago.setFecha(actual);
	pago.setImporte(importe);
	pago.setFecha(actual);
	pago.setFechaDesde(desde);
	pago.setFechaHasta(hasta);

	_accesoDatos.grabarPagoEnDisco(pago);


	return true;
}

int ReglasLogicas::cantidadDePagos() {
	return _accesoDatos.cantidad_registros_pagos();
}
Pagos ReglasLogicas::obtenerPago(int reg) {
	return _accesoDatos.obtenerPago(reg);
}
Pagos ReglasLogicas::obtenerUltimoPago(int id) {
	Pagos ultimo;
	int cantidad = _accesoDatos.cantidad_registros_pagos();
	for (int i = 0; i < cantidad; i++) {
		if (_accesoDatos.obtenerPago(i).getIdAlumno() == id) {
			ultimo = _accesoDatos.obtenerPago(i);
		}
	}
	return ultimo;
}

#pragma endregion

#pragma region Config
float ReglasLogicas::obtenerImporte(int tipoSus) {
	return _accesoDatos.obtenerImporte(tipoSus);
}
bool ReglasLogicas::ingresarConfig(Config config) {
	return _accesoDatos.grabarConfigDisco(config);
}

#pragma endregion
