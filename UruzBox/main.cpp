#include<iostream>
#include "Presentacion.h"
#include "Fecha.h"


using namespace std;

int main() {
	//Presentacion _presentacion;
	//_presentacion.MenuPrincipal();

	Fecha actual;
	Fecha aux(29, 7, 2022);
	if (actual > aux) {
		cout << "actual ES MAYOR QUE aux" << endl << endl;
	}
	else {
		cout << "aux ES MAYOR QUE actual" << endl << endl;
	}

	return 0;
}