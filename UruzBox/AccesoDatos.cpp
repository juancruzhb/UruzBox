#include "AccesoDatos.h"


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
bool AccesoDatos::GuardarEnDisco(Alumno alumno, int dni) {
	int reg = obtenerRegistroPorDni(dni);
	FILE* p = fopen("alumnos.dat", "rb+");
	if (p == NULL) {
		return false;
	}
	fseek(p, reg * sizeof(Alumno), SEEK_SET);
	bool guardo = fwrite(&alumno, sizeof(Alumno), 1, p);
	fclose(p);
	return guardo;
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
int  AccesoDatos::cantidad_registros_alumnos() {
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
int  AccesoDatos::obtenerRegistroPorDni(int dni) {
	int cantidad = cantidad_registros_alumnos();
	for (int i = 0; i < cantidad; i++) {
		if (obtenerAlumno(i).getDni() == dni) {
			return i;
		}
	}
	return -1;
}
int  AccesoDatos::obtenerRegistroPorApellido(std::string apellido) {
	int cantidad = cantidad_registros_alumnos();
	for (int i = 0; i < cantidad; i++) {
		std::string aux = obtenerAlumno(i).getApellido();
		if (aux.compare(apellido)==0 ){
			return i;
		}
	}
	return -1;

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
int  AccesoDatos::cantidad_registros_asistencias() {
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
Asistencia AccesoDatos::obtenerAsistencia(int reg) {
	Asistencia aux;

	FILE* p = fopen("asistencias.dat", "rb");

	fseek(p, reg * sizeof(Asistencia), SEEK_SET);
	bool ok = fread(&aux, sizeof(Asistencia), 1, p);
	fclose(p);
	return aux;
}
#pragma endregion

#pragma region Manipulacion de Pagos
bool AccesoDatos::grabarPagoEnDisco(Pagos pago) {
	FILE* p = fopen("pagos.dat", "ab");
	if (p == NULL) {
		return false;
	}
	bool guardo = fwrite(&pago, sizeof(Pagos), 1, p);
	fclose(p);
	return guardo;
}
int  AccesoDatos::cantidad_registros_pagos() {
	FILE* p = fopen("pagos.dat", "rb");
	if (p == NULL) {
		return 0;
	}

	int cantidad;
	size_t bytes;

	fseek(p, 0, SEEK_END);
	bytes = ftell(p);
	fclose(p);
	cantidad = bytes / sizeof(Pagos);
	return cantidad;
}
Pagos AccesoDatos::obtenerPago(int reg) {
	Pagos aux;
	FILE* p = fopen("pagos.dat", "rb");
	fseek(p, reg * sizeof(Pagos), SEEK_SET);
	bool ok = fread(&aux, sizeof(Pagos), 1, p);
	fclose(p);
	return aux;
}
#pragma endregion

#pragma region config
float AccesoDatos::obtenerImporte(int tipoSus) {
	Config aux;

	FILE* p = fopen("config.dat", "rb");
	if (p == nullptr) return 0;
	for (int i = 0; i < 3; i++) {
		fseek(p, i * sizeof(Config), SEEK_SET);
		fread(&aux, sizeof(Config), 1, p);
		if (tipoSus == 1)return aux.getT1();
		if (tipoSus == 2)return aux.getT2();
		if (tipoSus == 3)return aux.getT3();
	}
	return 0;

}
bool  AccesoDatos::grabarConfigDisco(Config config) {
	FILE* p = fopen("config.dat", "wb");
	if (p == NULL) {
		return false;
	}
	bool guardo = fwrite(&config, sizeof(config), 1, p);
	fclose(p);
	return guardo;
}
int   AccesoDatos::cantidad_registros_config() {
	FILE* p = fopen("config.dat", "rb");
	if (p == NULL) {
		return 0;
	}

	int cantidad;
	size_t bytes;

	fseek(p, 0, SEEK_END);
	bytes = ftell(p);
	fclose(p);
	cantidad = bytes / sizeof(Config);
	return cantidad;
}
Config AccesoDatos::obtenerConfig(int reg) {
	Config aux;
	FILE* p = fopen("config.dat", "rb");
	fseek(p, reg * sizeof(Config), SEEK_SET);
	bool ok = fread(&aux, sizeof(Config), 1, p);
	fclose(p);
	return aux;
}
#pragma endregion
