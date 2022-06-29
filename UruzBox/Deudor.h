#pragma once
#include<string>
#include "Fecha.h"
class Deudor
{
private:
	int _idAlumno;
	int _diasAtrasado;
	int _dni;
	int _idPago;
	char _nombre[50];
	char _apellido[50];
	float _importe;
	Fecha _ultimoPago;
	bool _deuda;
public:
	void setIdAlumno(int id);
	void setNombre(std::string nombre);
	void setApellido(std::string apellido);
	void setImporte(float importe); 
	void setDiasAtrasado(int dias);
	void setDni(int dni);
	void setDeuda(bool e);
	void setIdPago(int id);
	void setUltimoPago(Fecha fecha);
	int getIdAlumno();
	int getDni();
	int getIdPago();
	int getDiasAtrasado();
	bool getDeuda();
	std::string getNombre();
	std::string getApellido();
	Fecha getUltimoPago();
	float getImporte();

};

