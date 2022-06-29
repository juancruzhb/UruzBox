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

void Deudor::setDiasAtrasado(int dias)
{
	_diasAtrasado = dias;
}

void Deudor::setDeuda(bool e)
{
	_deuda = e;
}

int Deudor::getIdAlumno()
{
	return _idAlumno;
}

int Deudor::getDiasAtrasado()
{
	return _diasAtrasado;
}

bool Deudor::getDeuda()
{
	return _deuda;
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
