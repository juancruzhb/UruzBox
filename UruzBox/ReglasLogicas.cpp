#include "ReglasLogicas.h"
#include<iostream>
#include<string>
#include "Fecha.h"
#include"AccesoDatos.h"
#include <iomanip>
#include <vector>
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
bool ReglasLogicas::existeAlumnoPorApellido(std::string apellido) {
	int reg = _accesoDatos.obtenerRegistroPorApellido(apellido);
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
			if (alumno.getId() < _accesoDatos.cantidad_registros_alumnos() + 1) {
				alumno.setActivo(true);
				_accesoDatos.GuardarEnDisco(alumno, alumno.getDni());
				return alumno.getDni();
			}
			else {
				_accesoDatos.grabarAlumnoEnDisco(alumno);
				return alumno.getDni();
			}
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
bool ReglasLogicas::editarAlumno(Alumno alumno) {
	char opcion;
	cout << endl << endl;
	cout << "Uds va a editar al siguiente alumno: " << endl << endl << endl;

	mostrarDatosAlumno(alumno);

	cout << endl;
	cout << endl << endl << endl << endl;

	cout << "Desea confirmar la edicion? (s/n): ";
	cin >> opcion;
	if (tolower(opcion) == 's') {
		return _accesoDatos.GuardarEnDisco(alumno, alumno.getDni());
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
	char opcion;
	int id = _accesoDatos.cantidad_registros_alumnos() + 1;
	int dni, dia, mes, anio, celular, suscripcion;
	string nombre;
	string apellido;
	string mail; 
	cout << "DNI: ";
	cin >> dni;
	int reg = _accesoDatos.obtenerRegistroPorDni(dni);
	if (reg !=-1) {
		cout << "El alumno ya existe en los registros, desea recuperar datos? (s/n)" << endl;
		cin >> opcion;
		if (tolower(opcion) == 's') {
			return _accesoDatos.obtenerAlumno(reg);
		}
	}
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
Alumno ReglasLogicas::obtenerAlumnoConApellidoRepetido(std::string apellido) {
	int mismoApellido = 0;
	int cantidad = _accesoDatos.cantidad_registros_alumnos();
	Alumno* aux = new Alumno[cantidad];
	for (int i = 0; i < cantidad; i++) {
		aux[i] = _accesoDatos.obtenerAlumno(i);
		if (aux[i].getApellido() == apellido) {
			mismoApellido++;
		}
	}
	int pos = 0;
	Alumno* alumnos = new Alumno[mismoApellido];
	for (int j = 0; j < cantidad; j++) {
		if (aux[j].getApellido() == apellido) {
			alumnos[pos] = aux[j];
			pos++;
		}
	}

	cout << endl;
	cout << "SELECCIONE El ALUMNO QUE DESEA: " << endl << endl;
	for (int i = 0; i < mismoApellido; i++) {
		cout << i + 1 << "- " << alumnos[i].getApellido() << ", " << alumnos[i].getNombre() << " - " << alumnos[i].getDni() << endl;
	}
	int opcion;
	cout << "OPCION: ";
	cin >> opcion;
	
	Alumno seleccionado = alumnos[opcion - 1];

	delete aux;
	delete alumnos;
	return seleccionado;


}

/*std::vector<Alumno> alumnosConElMismoApellido(std::string apellido) {
	int mismoApellido = 0;
	int size = _accesoDatos.cantidad_registros_alumnos();
	Alumno *todos = new Alumno[size];
	for (int i = 0; i < size; i++) {
		todos[i] = _accesoDatos.obtenerAlumno(i);
		if (todos[i].getApellido() == apellido) {
			mismoApellido++;
		}
	}
	std::vector<Alumno> alumnos(mismoApellido);
	int pos = 0;

	for (int j = 0; j < size; j++) {
		if (alumnos[j].getApellido() == apellido) {
			alumnos[pos] = todos[j];
			pos++;
		}
	}
	delete todos;
	return alumnos;

}*/
#pragma endregion

#pragma region Manipulacion de Asistencias

bool ReglasLogicas::ingresarAsistencia(Alumno alumno) {
	int id = cantidadDeAsistencias() + 1;
	int idAlumno = alumno.getId();
	Asistencia asistencia(id, idAlumno);
	return _accesoDatos.grabarAsistenciaEnDisco(asistencia);
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
