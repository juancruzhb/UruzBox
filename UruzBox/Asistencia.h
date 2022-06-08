#pragma once
#include "Fecha.h"
class Asistencia
{
public:
	int getId();
	int getIdAlumno();
	Fecha getFecha();

	void setId(int id);
	void setIdAlumno(int idAlumno);

	Asistencia();
	Asistencia(int id, int idAlumno);

private:
	int _id;
	int _idAlumno;
	Fecha _fecha;
};

