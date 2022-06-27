#pragma once
class Presentacion
{
public:
	int MenuPrincipal();
	int MenuAlumnos();
	int MenuEditarAlumno();
	int MenuListados();
	int MenuAsistencias();
	int MenuReportes();
	int MenuCobranzas();
	void mostrarAlumnos();
	void mostrarAsistencias();
	void mostrarPagos();
	void cobrarCuota(int Ndni = 0);
	void exportarAlumnos();
	void eliminarAlumno();
	void configurar();
};

