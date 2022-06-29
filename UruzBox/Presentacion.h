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
	int MenuConsultas();
	int Menuconfigurar();
	void mostrarAlumnos();
	void ConsultaAlumno(int reg);
	void mostrarAsistencias(int nReg = -1);
	void mostrarPagos(int nReg = -1);
	void mostrarCuotasAtrasadas();
	void cobrarCuota(int Ndni = 0);
	void exportarAlumnos();
	void eliminarAlumno();
};

