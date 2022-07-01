#include "ReglasLogicas.h"

using namespace std;

AccesoDatos _accesoDatos;

#pragma region Prototipos
int calcularDiasAtrasados(Fecha actual, Fecha ultimoPago);
void mostrarMensaje2(string mensaje, int color, int colorFondo, int x, int y);
bool confirmarIngreso(Alumno reg);
void mostrarDatosAlumno(Alumno reg);
Alumno solicitarDatosAlumno(int dni);

#pragma endregion


#pragma region Manipulacion de Alumnos
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
int  ReglasLogicas::ingresarAlumno() {
	system("cls");
	int dni;
	cout << "Ingrese el DNI: ";
	cin >> dni;
	int reg = _accesoDatos.obtenerRegistroPorDni(dni);
	while (reg >= 0) {
		string mensaje = "El alumno ya existe";
		mostrarMensaje2(mensaje, 0, 4, 0, 0);
		cout << endl;
		cout << "Ingrese nuevamente el dni (0 para salir): ";
		cin >> dni;
		if (dni == 0) {
			return 0;
		}
		reg = _accesoDatos.obtenerRegistroPorDni(dni);
	}
	system("cls");
	cout << "DNI: " << dni << endl;
	Alumno alumno = solicitarDatosAlumno(dni);
	char opcion;
	cout << "Ha ingresado los siguientes datos" << endl << endl;
	mostrarDatosAlumno(alumno);
	cout << "Desea confirmar la carga de los datos? (s/n): ";
	cin >> opcion;
	if (tolower(opcion) == 's') {
		if (_accesoDatos.grabarAlumnoEnDisco(alumno)) {
			string mensaje = "El alumno fue ingresado con exito";
			mostrarMensaje2(mensaje, 0, 2, 0, 0);
			system("pause");
			return alumno.getDni();
		}
		
	}
	else {
		string mensaje = "No se grabo el alumno";
		mostrarMensaje2(mensaje, 0, 4, 0, 0);
		system("pause");
		return 0;
	}
	return 0;
}
bool ReglasLogicas::eliminarAlumno(Alumno alumno) {
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
		string mensaje = "El alumno ha sido eliminado con exito";
		mostrarMensaje2(mensaje, 0, 4, 0, 0);
		system("pause");
		return _accesoDatos.GuardarEnDisco(alumno, alumno.getDni());
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
int  ReglasLogicas::obtenerRegistroAlumnoPorDni(int dni) {
	return _accesoDatos.obtenerRegistroPorDni(dni);
}
int  ReglasLogicas::cantidadDeAlumnos(){
	return _accesoDatos.cantidad_registros_alumnos();
}

Alumno ReglasLogicas::obtenerAlumno(int reg, int dni) {
	if (dni == 0) {
			return _accesoDatos.obtenerAlumno(reg);
	}
	else {
		return _accesoDatos.obtenerAlumno(_accesoDatos.obtenerRegistroPorDni(dni));
	}
}
Alumno ReglasLogicas::obtenerAlumnoConApellidoRepetido(std::string apellido) {
	int mismoApellido = 0;
	int cantidad = _accesoDatos.cantidad_registros_alumnos();
	Alumno* aux = new Alumno[cantidad];
	for (int i = 0; i < cantidad; i++) {
		aux[i] = _accesoDatos.obtenerAlumno(i);
		if (aux[i].getApellido() == apellido && aux[i].getActivo()) {
			mismoApellido++;
		}
	}
	int pos = 0;
	Alumno* alumnos = new Alumno[mismoApellido];
	for (int j = 0; j < cantidad; j++) {
		if (aux[j].getApellido() == apellido && aux[j].getActivo()) {
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

	delete []aux;
	delete []alumnos;
	return seleccionado;


}

#pragma endregion

#pragma region Manipulacion de Asistencias
bool ReglasLogicas::ingresarAsistencia(Alumno alumno) {
	int id = cantidadDeAsistencias() + 1;
	int idAlumno = alumno.getId();
	Asistencia asistencia(id, idAlumno);
	return _accesoDatos.grabarAsistenciaEnDisco(asistencia);
}
int  ReglasLogicas::cantidadDeAsistencias() {
	return _accesoDatos.cantidad_registros_asistencias();
}

Asistencia ReglasLogicas::obtenerAsistencia(int reg) {
	return _accesoDatos.obtenerAsistencia(reg);
}
#pragma endregion

#pragma region Manipulacion de Pagos
bool  ReglasLogicas::ingresarPago(int idAlumno, float importe, Fecha desde, Fecha hasta) {
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
int   ReglasLogicas::cantidadDePagos() {
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


#pragma region Deudores

Deudor ReglasLogicas::obtenerDeudor(int reg)
{
	Alumno alumno = _accesoDatos.obtenerAlumno(reg);
	int pagos = _accesoDatos.cantidad_registros_pagos();
	Fecha actual;
	Fecha ultimoPago;
	Fecha fechaDePago;
	int  Idpago = -1;

	for (int i = 0; i < pagos; i++) {
		Pagos pago = _accesoDatos.obtenerPago(i);
		if (pago.getIdAlumno() == alumno.getId()) {
			ultimoPago = pago.getFechaHasta();
			fechaDePago = pago.getFecha();
			Idpago = pago.getId();
		}
	}
	int diasAtrasados = calcularDiasAtrasados(actual, ultimoPago);

	Deudor deudor;
	deudor.setApellido(alumno.getApellido());
	deudor.setNombre(alumno.getNombre());
	deudor.setDni(alumno.getDni());
	deudor.setIdAlumno(alumno.getId());
	deudor.setIdPago(Idpago);
	deudor.setDiasAtrasado(diasAtrasados);
	deudor.setDeuda(false);
	deudor.setImporte(100);
	deudor.setUltimoPago(fechaDePago);
	deudor.setActivo(alumno.getActivo());

	if (deudor.getIdPago() < 0) {
		diasAtrasados = calcularDiasAtrasados(actual, alumno.getFechaAlta());
		deudor.setDiasAtrasado(diasAtrasados);
		deudor.setDeuda(true);
		return deudor;
	}

	if (actual > ultimoPago) {
		deudor.setDeuda(true);
		return deudor;
	}
	

	return deudor;

}

#pragma endregion


#pragma region Config
float  ReglasLogicas::obtenerImporte(int tipoSus) {
	return _accesoDatos.obtenerImporte(tipoSus);
}
bool   ReglasLogicas::ingresarConfig(Config config) {
	return _accesoDatos.grabarConfigDisco(config);
}
int    ReglasLogicas::cantidadConfig() {
	return _accesoDatos.cantidad_registros_config();
}
Config ReglasLogicas::obtenerConfig(int reg) {
	return _accesoDatos.obtenerConfig(reg);
}
#pragma endregion

#pragma region Funciones Auxiliares
int calcularDiasAtrasados(Fecha actual, Fecha ultimoPago) {
	int ddB = actual.getDia();
	int mmB = actual.getMes();
	int aaB = actual.getAnio() - 1900;

	int ddA = ultimoPago.getDia();
	int mmA = ultimoPago.getMes();
	int aaA = ultimoPago.getAnio() - 1900;

	int diferencia = 0;
	struct std::tm a = { 0,0,0,ddA,mmA,aaA }; 
	struct std::tm b = { 0,0,0,ddB,mmB,aaB }; 
	std::time_t x = std::mktime(&a);
	std::time_t y = std::mktime(&b);
	if (x != (std::time_t)(-1) && y != (std::time_t)(-1))
	{
		diferencia = std::difftime(y, x) / (60 * 60 * 24);
		
	}
	return diferencia;

}
void mostrarMensaje2(string mensaje, int color, int colorFondo, int x, int y) {
	rlutil::saveDefaultColor();
	rlutil::locate(x, y);
	rlutil::setColor(color);
	rlutil::setBackgroundColor(colorFondo);
	cout << endl << endl;
	cout << mensaje << endl << endl;
	rlutil::resetColor();
}
bool confirmarIngreso(Alumno reg) {
	char opcion;
	cout << endl << endl;
	cout << "Uds ha ingresado los siguientes datos: " << endl << endl << endl;

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
	cout << std::setfill(' ') << std::setw(112);
	cout << setw(12) << "DNI";
	cout << setw(15) << "APELLIDO";
	cout << setw(15) << "NOMBRE";
	cout << setw(15) << "FECHA";
	cout << setw(25) << "EMAIL";
	cout << setw(15) << "CELULAR";
	cout << setw(15) << "SUSCRIPCION" << endl;


	cout << "-------------------------------------------------------------------------------------------------------------------" << endl;
	cout << left;
	cout << std::setfill(' ') << std::setw(112);
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
Alumno solicitarDatosAlumno(int dni) {
	char opcion;
	int id = _accesoDatos.cantidad_registros_alumnos() + 1;
	int dia, mes, anio, celular, suscripcion;
	string nombre;
	string apellido;
	string mail;

	cout << "APELLIDO: ";
	cin >> apellido;
	cout << "NOMBRE: ";
	cin >> nombre;
	cout << "DIA DE NACIMIENTO: ";
	cin >> dia;
	cout << "MES DE NACIMIENTO: ";
	cin >> mes;
	cout << "ANIO DE NACIMIENTO: ";
	cin >> anio;
	cout << "CELULAR: ";
	cin >> celular;
	cout << "E-MAIL: ";
	cin >> mail;
	cout << "Suscripcion:" << endl;
	cout << " 1. 2 veces por semana" << endl;
	cout << " 2. 3 veces por semana" << endl;
	cout << " 3. Libre" << endl;
	cout << "Opcion: ";
	cin >> suscripcion;
	Contacto contacto(celular, mail);
	Fecha fecha(dia, mes, anio);
	Alumno alumno(id, dni, apellido, nombre, fecha, contacto, suscripcion);
	return alumno;
}
#pragma endregion
