#include "Pagos.h"
#include<string>
#include<cstring>

void Pagos::setId(int id)
{
	_id = id;
}

void Pagos::setIdAlumno(int idAlumno)
{
	_idAlumno = idAlumno;
}

void Pagos::setFecha(Fecha fecha)
{
	_fecha = fecha;
}

void Pagos::setImporte(float importe)
{
	_importe = importe;
}

void Pagos::setFechaHasta(Fecha fecha)
{
	_fechaHasta = fecha;
	//TODO: validar fechas
}
void Pagos::setFechaDesde(Fecha fecha) {
	_fechaDesde = fecha;
}


int Pagos::getId()
{
	return _id;
}

int Pagos::getIdAlumno()
{
	return _idAlumno;
}

float Pagos::getImporte()
{
	return _importe;
}

Fecha Pagos::getFecha()
{
	return _fecha;
}

Fecha Pagos::getFechaDesde()
{
	return _fechaDesde;
}

Fecha Pagos::getFechaHasta()
{
	return _fechaHasta;
}


