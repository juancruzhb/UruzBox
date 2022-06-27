#pragma once
#include<string>
class Deudor
{
private:
	int _idAlumno;
	char _nombre[50];
	char _apellido[50];
	float _importe;
public:
	void setIdAlumno(int id);
	void setNombre(std::string nombre);
	void setApellido(std::string apellido);
	void setImporte(float importe); 
	int getIdAlumno();
	std::string getNombre();
	std::string getApellido();
	float getImporte();
};

