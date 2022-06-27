#pragma once
#include"Fecha.h"
class Pagos
{
private:
	int _id, _idAlumno;
	float _importe;
	Fecha _fecha;
	Fecha _fechaDesde;
	Fecha _fechaHasta;
public:
	void setId(int id);
	void setIdAlumno(int idAlumno);
	void setFecha(Fecha fecha);
	void setImporte(float importe);
	void setFechaDesde(Fecha fecha);
	void setFechaHasta(Fecha fecha);
	int getId();
	int getIdAlumno();
	float getImporte();
	Fecha getFecha();
	Fecha getFechaDesde();
	Fecha getFechaHasta();
};

