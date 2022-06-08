#include "Alumno.h"


#pragma region Constructor
Alumno::Alumno(){

};
Alumno::Alumno(int id, int dni, std::string apellido, std::string nombre, Fecha fechaNac, Contacto contacto, int suscripcion) {
	Fecha fechaActual;
	_id = id;
	_dni = dni;
	_fechaNac = fechaNac;
	_fechaAlta = fechaActual;
	_activo = true;
	_contacto = contacto;
	_suscripcion = suscripcion;
	strcpy(_apellido, apellido.c_str());
	strcpy(_nombre, nombre.c_str());

}
#pragma endregion

#pragma region setters
void  Alumno::setID(int id) {
	_id = id;
}
void  Alumno::setDni(int dni) {
	_dni = dni;
}
void  Alumno::setNombre(std::string nombre) {
	strcpy(_nombre, nombre.c_str());
}
void  Alumno::setApellido(std::string apellido) {
	strcpy(_apellido, apellido.c_str());
}
void  Alumno::setActivo(bool e) {
	_activo = e;
}
void  Alumno::setFechaNac(Fecha fecha) {
	_fechaNac = fecha;
}
void Alumno::setContacto(Contacto contacto) {
	_contacto = contacto;
}
#pragma endregion

#pragma region getters
int   Alumno::getId() {
	return _id;
}
int   Alumno::getDni() {
	return _dni;
}
bool  Alumno::getActivo() {
	return _activo;
}
Fecha Alumno::getFechaNac() {
	return _fechaNac;
}
Fecha Alumno::getFechaAlta()
{
	return _fechaAlta;
}
Contacto Alumno::getContacto() {
	return _contacto;
}
int   Alumno::getEdad() {
	Fecha actual;
	Fecha nacimiento = _fechaNac;
	int edad = actual.getAnio() - nacimiento.getAnio();
	if (actual.getAnio() > nacimiento.getAnio() && actual.getMes() > nacimiento.getMes()) {
		return edad;
	}
	else if (actual.getMes() == nacimiento.getMes() && actual.getDia() >= nacimiento.getDia()) {
		return edad;
	}
	else {
		return edad - 1;
	}
}
std::string Alumno::getSuscripcion()
{
	std::string suscripcion;
	if (_suscripcion == 1) {
		suscripcion = "2 por semana";
	}
	else if (_suscripcion == 2) {
		suscripcion = "3 por semana";
	}
	else {
		suscripcion = "Libre";
	}
	return suscripcion;
}
std::string Alumno::getNombre() {
	std::string nombre;
	nombre = _nombre;
	return nombre;
}
std::string Alumno::getApellido() {
	std::string apellido;
	apellido = _apellido;
	return apellido;
}
std::string Alumno::mostrarFechaAlta() {
	std::string fechaAlta;
	return fechaAlta = std::to_string(_fechaAlta.getDia()) + "/" + std::to_string(_fechaAlta.getMes()) + "/" + std::to_string(_fechaAlta.getAnio());
}
#pragma endregion

