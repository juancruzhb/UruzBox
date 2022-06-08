#pragma once
#include"Fecha.h"
#include"Contacto.h"
#include<string>
#include<cstring>
class Alumno
{
public:
	void setID(int id);
	void setDni(int dni);
	void setNombre(std::string nombre);
	void setApellido(std::string apellido);
	void setActivo(bool e);
	void setFechaNac(Fecha fecha);
	void setContacto(Contacto contacto);

	int getId();
	int getDni();
	int getEdad();
	std::string getSuscripcion();
	std::string getNombre();
	std::string getApellido();
	std::string mostrarFechaAlta();
	bool getActivo();
	Fecha getFechaNac();
	Fecha getFechaAlta();
	Contacto getContacto();
	Alumno();
	Alumno(int id, int dni, std::string apellido, std::string nombre, Fecha fechaNac, Contacto contacto, int suscripcion);


private:
	int _id;
	int _dni;
	int _suscripcion;
	char _nombre[50];
	char _apellido[50];
	bool _activo;
	Fecha _fechaNac;
	Fecha _fechaAlta;
	Contacto _contacto;
};

