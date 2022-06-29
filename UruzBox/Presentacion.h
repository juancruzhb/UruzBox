#pragma once
#include"Alumno.h"
class Presentacion
{
public:
	int MenuPrincipal();
	int MenuAlumnos();
	int MenuEditarAlumno(Alumno alumno);
	int MenuListados();
	int MenuAsistencias();
	int MenuReportes();
	int MenuCobranzas();
	int Menuconfigurar();
	void mostrarAlumnos();
	void mostrarAsistencias();
	void mostrarPagos();
	void mostrarCuotasAtrasadas();
	void cobrarCuota(int Ndni = 0);
	void exportarAlumnos();
	void eliminarAlumno();
};

