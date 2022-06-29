#pragma once
#include "Alumno.h"
#include"Contacto.h"
#include"Asistencia.h"
#include "Pagos.h"
#include"Config.h"
#include"Deudor.h"
class ReglasLogicas
{
public:
	int ingresarAlumno();
	bool eliminarAlumno(Alumno alumno);
	bool editarAlumno(Alumno alumno);
	Alumno obtenerAlumno(int reg, int dni = 0);
	int cantidadDeAlumnos();

	bool ingresarAsistencia(Alumno alumno);
	Asistencia obtenerAsistencia(int reg);
	int cantidadDeAsistencias();
	bool ingresarPago(int idAlumno, float importe, Fecha desde, Fecha hasta);
	int cantidadDePagos();
	Pagos obtenerPago(int reg);
	Pagos obtenerUltimoPago(int id);
	float obtenerImporte(int tipoSus);

	bool ingresarConfig(Config config);
	int cantidadConfig();
	Config obtenerConfig(int reg);;
	bool existeAlumno(int dni);
	bool existeAlumnoPorApellido(std::string apellido);


	Alumno obtenerAlumnoConApellidoRepetido(std::string apellido);

	Deudor obtenerDeudor(int reg);
};

