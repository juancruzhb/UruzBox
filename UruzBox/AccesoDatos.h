#pragma once
#include"Alumno.h"
#include"Asistencia.h"
#include"Pagos.h"
#include <iostream>
#include"Config.h"
class AccesoDatos
{
public:
#pragma region Alumnos
	bool grabarAlumnoEnDisco(Alumno alumno);
	bool GuardarEnDisco(Alumno alumno, int dni);
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
	int cantidad_registros_pagos();
#pragma endregion

#pragma region Pagos
	bool grabarPagoEnDisco(Pagos cobro);
	Pagos obtenerPago(int reg);
#pragma endregion

#pragma region Config
	float obtenerImporte(int tipoSus);
	bool grabarConfigDisco(Config config);
	int cantidad_registros_config();
	Config obtenerConfig(int reg);
#pragma endregion

};
