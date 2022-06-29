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

void Deudor::setDni(int dni)
{
	_dni = dni;
}

void Deudor::setDeuda(bool e)
{
	_deuda = e;
}

void Deudor::setIdPago(int id)
{
	_idPago = id;
}

void Deudor::setUltimoPago(Fecha fecha)
{
	_ultimoPago = fecha;
}

int Deudor::getIdAlumno()
{
	return _idAlumno;
}

int Deudor::getDni()
{
	return _dni;
}

int Deudor::getIdPago()
{
	return _idPago;
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

Fecha Deudor::getUltimoPago()
{
	return _ultimoPago;
}

float Deudor::getImporte()
{
	return _importe;
}
