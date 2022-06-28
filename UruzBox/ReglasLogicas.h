#pragma once
#include "Alumno.h"
#include"Contacto.h"
#include"Asistencia.h"
#include "Pagos.h"
#include"Config.h"
class ReglasLogicas
{
public:
	int ingresarAlumno();
	bool eliminarAlumno(int dni);
	bool editarAlumno(Alumno alumno);
	Alumno obtenerAlumno(int reg, int dni = 0);
	int cantidadDeAlumnos();

	bool ingresarAsistenciaPorDni();
	bool ingresarAsistenciaPorApellido();
	Asistencia obtenerAsistencia(int reg);
	int cantidadDeAsistencias();
	bool ingresarPago(int idAlumno, float importe, Fecha desde, Fecha hasta);
	int cantidadDePagos();
	Pagos obtenerPago(int reg);
	Pagos obtenerUltimoPago(int id);
	float obtenerImporte(int tipoSus);

	bool ingresarConfig(Config config);
	bool existeAlumno(int dni);


	void obtenerAlumnosRepetidosPorApellido(std::string apellido);
};

