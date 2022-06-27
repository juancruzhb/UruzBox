#include "Deudor.h"

void Deudor::setIdAlumno(int id)
{
	_idAlumno = id;
}

void Deudor::setNombre(std::string nombre)
{
	strcpy(_nombre, nombre.c_str());
}

void Deudor::setApellido(std::string apellido)
{
	strcpy(_apellido, apellido.c_str());
}

void Deudor::setImporte(float importe)
{
	_importe = importe;
}

int Deudor::getIdAlumno()
{
	return _idAlumno;
}

std::string Deudor::getNombre()
{
	std::string nombre;
	nombre = _nombre;
	return nombre;
}

std::string Deudor::getApellido()
{
	std::string apellido;
	apellido = _apellido;
	return apellido;
}

float Deudor::getImporte()
{
	return _importe;
}
