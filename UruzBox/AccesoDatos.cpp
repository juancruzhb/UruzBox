#include "AccesoDatos.h"
#include <iostream>


#pragma region Manipulacion de Alumnos

bool AccesoDatos::grabarAlumnoEnDisco(Alumno alumno) {
	FILE* p = fopen("alumnos.dat", "ab");
	if (p == NULL) {
		return false;
	}
	bool guardo = fwrite(&alumno, sizeof(Alumno), 1, p);
	fclose(p);
	return guardo;
}

Alumno AccesoDatos::obtenerAlumno(int reg) {
	Alumno aux;

	FILE* p = fopen("alumnos.dat", "rb");
	//if (p == nullptr) return;

	fseek(p, reg * sizeof(Alumno), SEEK_SET);
	bool ok = fread(&aux, sizeof(Alumno), 1, p);
	fclose(p);
	return aux;
}

bool AccesoDatos::leerDeDisco(int reg) {
	//Alumno aux;
	FILE* p = fopen("alumnos.dat", "rb");
	if (p == NULL) {
		return false;
	}
	fseek(p, reg * sizeof(Alumno), SEEK_SET);
	bool ok = fread(this, sizeof(Alumno), 1, p);
	fclose(p);
	return ok;
}

int AccesoDatos::cantidad_registros_alumnos() {
	FILE *p = fopen("alumnos.dat", "rb");
	if (p == NULL) {
		return 0;
	}

	int cantidad;
	size_t bytes;

	fseek(p, 0, SEEK_END);
	bytes = ftell(p);
	fclose(p);
	cantidad = bytes / sizeof(Alumno);
	return cantidad;
}

int AccesoDatos::obtenerRegistroPorDni(int dni) {
	int cantidad = cantidad_registros_alumnos();
	for (int i = 0; i < cantidad; i++) {
		if (obtenerAlumno(i).getDni() == dni) {
			return i;
		}
	}
	return -1;
}

int AccesoDatos::obtenerRegistroPorApellido(std::string apellido) {
	int cantidad = cantidad_registros_alumnos();
	for (int i = 0; i < cantidad; i++) {
		std::string aux = obtenerAlumno(i).getApellido();
		if (aux.compare(apellido)==0 ){
			return i;
		}
	}
	return -1;

}
#pragma endregion

#pragma region Manipulacion de asistencias
bool AccesoDatos::grabarAsistenciaEnDisco(Asistencia asistencia) {
	FILE* p = fopen("asistencias.dat", "ab");
	if (p == NULL) {
		return false;
	}
	bool guardo = fwrite(&asistencia, sizeof(Asistencia), 1, p);
	fclose(p);
	return guardo;
}
Asistencia AccesoDatos::obtenerAsistencia(int reg) {
	Asistencia aux;

	FILE* p = fopen("asistencias.dat", "rb");

	fseek(p, reg * sizeof(Asistencia), SEEK_SET);
	bool ok = fread(&aux, sizeof(Asistencia), 1, p);
	fclose(p);
	return aux;
}
int AccesoDatos::cantidad_registros_asistencias() {
	FILE* p = fopen("asistencias.dat", "rb");
	if (p == NULL) {
		return 0;
	}

	int cantidad;
	size_t bytes;

	fseek(p, 0, SEEK_END);
	bytes = ftell(p);
	fclose(p);
	cantidad = bytes / sizeof(Asistencia);
	return cantidad;
}
#pragma endregion
