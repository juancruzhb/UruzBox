#pragma once
#include"Alumno.h"
#include"Asistencia.h"
class AccesoDatos
{
public:
#pragma region Alumnos
	bool grabarAlumnoEnDisco(Alumno alumno);
	Alumno obtenerAlumno(int reg);
	bool leerDeDisco(int reg);
	int cantidad_registros_alumnos();
	int obtenerRegistroPorDni(int dni);
	int obtenerRegistroPorApellido(std::string apellido);
#pragma endregion

#pragma region Asistencias
	bool grabarAsistenciaEnDisco(Asistencia asistencia);
	Asistencia obtenerAsistencia(int reg);
	int cantidad_registros_asistencias();
#pragma endregion

};
