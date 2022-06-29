#include<iostream>
#include "Presentacion.h"
#include "Fecha.h"
#include"ReglasLogicas.h"
#include"Deudor.h"

using namespace std;

int main() {

	Presentacion _presentacion;
	//_presentacion.MenuPrincipal();

	_presentacion.mostrarCuotasAtrasadas();


	return 0;
}