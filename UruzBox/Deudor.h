#pragma once
#include<string>
#include "Fecha.h"
class Deudor
{
private:
	int _idAlumno;
	int _diasAtrasado;
	char _nombre[50];
	char _apellido[50];
	float _importe;
	Fecha ultimoPago;
	bool _deuda;
public:
	void setIdAlumno(int id);
	void setNombre(std::string nombre);
	void setApellido(std::string apellido);
	void setImporte(float importe); 
	void setDiasAtrasado(int dias);
	void setDeuda(bool e);
	int getIdAlumno();
	int getDiasAtrasado();
	bool getDeuda();
	std::string getNombre();
	std::string getApellido();
	float getImporte();

};

