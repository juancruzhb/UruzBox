#pragma once
#include "Alumno.h"
#include"Contacto.h"
#include"Asistencia.h"
class ReglasLogicas
{
public:
	bool ingresarAlumno();
	Alumno obtenerAlumno(int reg);
	int cantidadDeAlumnos();

	bool ingresarAsistenciaPorDni();
	bool ingresarAsistenciaPorApellido();
	Asistencia obtenerAsistencia(int reg);
	int cantidadDeAsistencias();

};

