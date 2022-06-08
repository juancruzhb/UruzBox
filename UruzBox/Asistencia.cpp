#include "Asistencia.h"

int Asistencia::getId() {
	return _id;
}

int Asistencia::getIdAlumno()
{
	return _idAlumno;
}

Fecha Asistencia::getFecha()
{
	return _fecha;
}

void Asistencia::setId(int id)
{
	_id = id;
}

void Asistencia::setIdAlumno(int idAlumno)
{
	_idAlumno = idAlumno;
}

Asistencia::Asistencia()
{
}

Asistencia::Asistencia(int id, int idAlumno)
{
	Fecha actual;
	_id = id;
	_idAlumno = idAlumno;
	_fecha = actual;

}
