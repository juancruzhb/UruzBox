#include <iostream>
#include<iomanip>
#include "Presentacion.h"
#include"ReglasLogicas.h"
#include"Config.h"
using namespace std;

ReglasLogicas _reglasLogicas;

#pragma region Menus
int Presentacion::MenuPrincipal()
{
    int opcion;
    char confirmarSalida;
    while (true) {
        system("cls");
        cout << "Menu Principal" << endl;
        cout << "--------------------------" << endl;
        cout << "1 - Ingresar Asistencia" << endl;
        cout << "2 - Gestion de Alumnos" << endl;
        cout << "3 - Cobranzas" << endl;
        cout << "4 - Listados" << endl;
        cout << "5 - Reportes" << endl;
        cout << "6 - Configurar" << endl;
        cout << "--------------------------" << endl;
        cout << "0 - Salir del programa" << endl << endl;

        cout << "Opcion: ";
        cin >> opcion;

        switch (opcion) {
        case 1:
            MenuAsistencias();
            break;
        case 2:            
            MenuAlumnos();
            break;
        case 3:
            cobrarCuota();
            break;
        case 4:
            MenuListados();
            break;
        case 5:
            MenuReportes();
            break;
        case 6:
            configurar();
            break;
        case 0:
            cout << "¿Confirma salir? (S/N) ";
            cin >> confirmarSalida;
            if (tolower(confirmarSalida) == 's') {
                return 0;
            }
            break;
        }
        cin.ignore();
    }
}
int Presentacion::MenuAlumnos() {
    system("cls");
    int opcion;
    char confirmarSalida;
    while (true) {
        system("cls");
        cout << "Menu Alumnos" << endl;
        cout << "--------------------------" << endl;
        cout << "1 - Ingresar Alumno" << endl;
        cout << "2 - Editar Alumno" << endl;
        cout << "3 - Eliminar Alumno" << endl;
        cout << "--------------------------" << endl;
        cout << "0 - Regresar al menu principal" << endl << endl;

        cout << "Opcion: ";
        cin >> opcion;

        switch (opcion) {
        case 1:
            if (_reglasLogicas.ingresarAlumno() ) {
                cout << endl << endl;
                cout << "SE HA INGRESADO CORRECTAMENTE EL ALUMNO" << endl << endl;
                system("pause");
            }
            else {
                cout << endl << "No se pudo ingresar el alumno";
            }
            
            break;
        case 2:
            //menu_examenes();
            break;
        case 3:
            //menu_reportes();
            break;
        case 0:
            return 0;
            break;
        }
        cin.ignore();
    }

}
int Presentacion::MenuListados() {
    system("cls");
    int opcion;
    char confirmarSalida;
    while (true) {
        cout << "Menu Listado" << endl;
        cout << "--------------------------" << endl;
        cout << "1 - Listar Alumnos" << endl;
        cout << "2 - Listar Asistencias" << endl;
        cout << "3 - Listar Pagos" << endl;
        cout << "--------------------------" << endl;
        cout << "0 - Volver al menu principal" << endl << endl;

        cout << "Opcion: ";
        cin >> opcion;

        switch (opcion) {
        case 1:
            mostrarAlumnos();
            break;
        case 2:
            mostrarAsistencias();
            break;        
        case 3:
                mostrarPagos();
                break;
        case 0:
            cout << "Opcion: ";
                return 0;
            break;
        }
        cin.ignore();
    }

}
int Presentacion::MenuAsistencias() {
    system("cls");
    int opcion;
    char confirmarSalida;
    while (true) {
        system("cls");
        cout << "Ingresar la asistencia por:" << endl;
        cout << "--------------------------" << endl;
        cout << "1 - DNI" << endl;
        cout << "2 - Apellido" << endl;
        cout << "--------------------------" << endl;
        cout << "0 - Volver al Menu principal" << endl << endl;

        cout << "Opcion: ";
        cin >> opcion;

        switch (opcion) {
        case 1:
            if (_reglasLogicas.ingresarAsistenciaPorDni()) {
                cout << endl << endl;
                cout << "Se ha ingresado una asistencia con exito"<<endl<<endl;
            }
            else {
                cout << "Corrobore los datos" << endl;
            }
            system("pause");
            
            break;
        case 2:
            if (_reglasLogicas.ingresarAsistenciaPorApellido()) {
                cout << endl << endl;
                cout << "Se ha ingresado una asistencia con exito" << endl << endl;
            }
            else {
                cout << "Corrobore los datos" << endl;
            }
            system("pause");
            break;
        case 0:
            return 0;
            break;
        }
        cin.ignore();
    }
}
int Presentacion::MenuReportes() {
    system("cls");
    int opcion;
    char confirmarSalida;
    while (true) {
        system("cls");
        cout << "Menu Reportes" << endl;
        cout << "--------------------------" << endl;
        cout << "1 - Exportar alumnos" << endl;
        //cout << "2 - Editar Alumno" << endl;
        //cout << "3 - Eliminar Alumno" << endl;
        //cout << "--------------------------" << endl;
        cout << "0 - Regresar al menu principal" << endl << endl;
        cout << "Opcion: ";
        cin >> opcion;

        switch (opcion) {
        case 1:
            exportarAlumnos();
            break;
        case 2:
            //mostrarAsistencias();
            break;
        case 0:
            cout << "Opcion: ";
            return 0;
            break;
        }
        cin.ignore();
    }
}
int Presentacion::MenuCobranzas() {
    system("cls");
    int opcion;
    char confirmarSalida;
    while (true) {
        system("cls");
        cout << "Cobranzas" << endl;
        cout << "--------------------------" << endl;
        cout << "1 - Ingresar un pago" << endl;
        cout << "2 - CashFlow Alumno" << endl;
        cout << "3 - ";
        //cout << "--------------------------" << endl;
        cout << "0 - Regresar al menu principal" << endl << endl;
        cout << "Opcion: ";
        cin >> opcion;

        switch (opcion) {
        case 1:
            break;
        case 2:
            //mostrarAsistencias();
            break;
        case 0:
            cout << "Opcion: ";
            return 0;
            break;
        }
        cin.ignore();
    }
}
#pragma endregion

void Presentacion::mostrarAlumnos() {

    int cantidad = _reglasLogicas.cantidadDeAlumnos();
    Alumno* alumnos = new Alumno[cantidad];
    if (alumnos == nullptr) {        
        cout << endl;
        cout << "Error al mostrar los alumnos" << endl << endl;
    }
    for (int i = 0; i < cantidad; i++) {
        alumnos[i] = _reglasLogicas.obtenerAlumno(i);
    }
    system("cls");

    cout << left;
    cout << setw(4) << "ID";
    cout << setw(12) << "   DNI";
    cout << setw(15) << "APELLIDO";
    cout << setw(15) << "NOMBRE";
    cout << setw(6) << "EDAD";
    cout << setw(25) << "      EMAIL";
    cout << setw(15) << "CELULAR";
    cout << setw(15) << "MIEMBRO DESDE";
    cout << setw(15) << "SUSCRIPCION" << endl;

    cout << "---------------------------------------------------------------------------------------------------------" << endl;


    for (int i = 0; i < cantidad; i++) {
        cout << left;
        cout << setw(4) << alumnos[i].getId();
        cout << setw(12) << alumnos[i].getDni();
        cout << setw(15) << alumnos[i].getApellido();
        cout << setw(15) << alumnos[i].getNombre();
        cout << setw(6) << alumnos[i].getEdad();
        cout << setw(25) << alumnos[i].getContacto().getMail();
        cout << setw(15) << alumnos[i].getContacto().getCelular();
        cout << setw(15) << alumnos[i].mostrarFechaAlta();
        cout << setw(15) << alumnos[i].getSuscripcionString();

        cout << endl;
    }
    cout << endl << endl << endl << endl;

    delete []alumnos;

   system("pause");
   system("cls");
}
void Presentacion::mostrarAsistencias() {
    int cantidadAsis = _reglasLogicas.cantidadDeAsistencias();
    int cantidadAlum = _reglasLogicas.cantidadDeAlumnos();
    Asistencia* aux = new Asistencia[cantidadAsis];
    Alumno* reg = new Alumno[cantidadAlum];

    if (aux == nullptr || reg == nullptr) {
        cout << endl << endl;
        cout << "No se pudo listar las asistencias";
        cout << endl << endl;
    }
    for (int i = 0; i < cantidadAsis; i++) {
        aux[i] = _reglasLogicas.obtenerAsistencia(i);
    }
    for (int j = 0; j < cantidadAlum; j++) {
        reg[j] = _reglasLogicas.obtenerAlumno(j);
    }


    system("cls");
    cout << left;
    cout << setw(6) << "ID";
    cout << setw(15) << "APELLIDO";
    cout << setw(15) << "NOMBRE";
    cout << setw(15) << "FECHA" << endl;

    cout << "-------------------------------------------------------" << endl;


    for (int i = 0; i < cantidadAsis; i++) {
        for (int j = 0; j < cantidadAlum; j++) {
            if (aux[i].getIdAlumno() == reg[j].getId()) {
                cout << left;
                cout << setw(6) << aux[i].getId();
                cout << setw(12) << reg[j].getApellido();
                cout << setw(15) <<reg[j].getNombre();
                cout << setw(15) <<aux[i].getFecha().toString();
                cout << endl;
            }
        }
    }
    cout << endl << endl << endl << endl;
    delete []aux;
    delete []reg;
    system("pause");
    system("cls");
}
void Presentacion::cobrarCuota() {
    system("cls");
    char opcion;
    int dni;
    float importe;
    cout << "Ingrese el DNI: ";
    cin >> dni;
    Alumno alumno = _reglasLogicas.obtenerAlumno(-1, dni);
    importe = _reglasLogicas.obtenerImporte(alumno.getSuscripcion());
    cout << "Precio correspondiente a la suscripcion: " << importe << endl;
    cout << "Desea ingresar el pago? (s/n): ";
    cin >> opcion;
    if (tolower(opcion) == 's') {
        if (_reglasLogicas.ingresarPago(alumno.getId(), importe)) {
            cout << endl;
            cout << "Se ha ingresado el pago con exito" << endl << endl;
       }
    }
    system("pause");
}
void Presentacion::mostrarPagos() {
    int cantidadCobros = _reglasLogicas.cantidadDePagos();
    int cantidadAlum = _reglasLogicas.cantidadDeAlumnos();
    Pagos* aux = new Pagos[cantidadCobros];
    Alumno* reg = new Alumno[cantidadAlum];

    if (aux == nullptr || reg == nullptr) {
        cout << endl << endl;
        cout << "No se pudo listar los cobros";
        cout << endl << endl;
    }
    for (int i = 0; i < cantidadCobros; i++) {
        aux[i] = _reglasLogicas.obtenerPago(i);
    }
    for (int j = 0; j < cantidadAlum; j++) {
        reg[j] = _reglasLogicas.obtenerAlumno(j);
    }


    system("cls");
    cout << left;
    cout << setw(10) << "ID COBRO";
    cout << setw(15) << "APELLIDO";
    cout << setw(15) << "NOMBRE";
    cout << setw(15) << "MONTO";
    cout << setw(15) << "DESDE";
    cout << setw(15) << "HASTA" << endl;


    cout << "-------------------------------------------------------" << endl;


    for (int i = 0; i < cantidadCobros; i++) {
        for (int j = 0; j < cantidadAlum; j++) {
            if (aux[i].getIdAlumno() == reg[j].getId()) {
                cout << left;
                cout << setw(10) << aux[i].getId();
                cout << setw(12) << reg[j].getApellido();
                cout << setw(15) << reg[j].getNombre();
                cout << setw(15) << aux[j].getImporte();
                cout << setw(15) << aux[i].getFecha().toString();
                cout << setw(15) << aux[i].getFechaVencimiento().toString();
                cout << endl;
            }
        }
    }
    cout << endl << endl << endl << endl;
    delete[]aux;
    delete[]reg;
    system("pause");
    system("cls");
}
void Presentacion::configurar() {
    system("cls");
    int opcion;
    char confirmarSalida;
    while (true) {
        system("cls");
        cout << "CONFIGURACION" << endl;
        cout << "--------------------------" << endl;
        cout << "1 - Modificar valores de la cuota" << endl;
        //cout << "2 - Editar Alumno" << endl;
        //cout << "3 - Eliminar Alumno" << endl;
        //cout << "--------------------------" << endl;
        cout << "0 - Regresar al menu principal" << endl << endl;
        cout << "Opcion: ";
        cin >> opcion;
        
        float tipo1, tipo2, tipo3;
        switch (opcion) {
        case 1:
        {
            system("cls");
            cout << "Nuevo precio para 2 veces por semana: ";
            cin >> tipo1;
            cout << "Nuevo precio para 3 veces por semana: ";
            cin >> tipo2;
            cout << "Nuevo precio modalidad libre: ";
            cin >> tipo3;
            Config config(tipo1, tipo2, tipo3);
            if (_reglasLogicas.ingresarConfig(config)) {
                cout << endl;
                cout << "CAMBIOS GUARDADOS" << endl << endl;
            }
            system("pause");
        }
                    
            break;
        case 0:
            cout << "Opcion: ";
            return;
            break;
        }
        cin.ignore();
    }
}
void Presentacion::exportarAlumnos() {
    int cantAlumnos = _reglasLogicas.cantidadDeAlumnos();
    Alumno *alumnos = new Alumno[cantAlumnos];
    if (alumnos == nullptr)return;
    for (int i = 0; i < cantAlumnos; i++) {
        alumnos[i]= _reglasLogicas.obtenerAlumno(i);
    }

    cout <<"ID" << "," << "DNI"<< "," <<"APELLIDO"<< "," << "NOMBRE"<< "," << "EMAIL"<< "," <<"CELULAR" << endl;

    for (int i = 0; i < cantAlumnos; i++) {
        cout << alumnos[i].getId() << "," << alumnos[i].getDni() << "," << alumnos[i].getApellido() << "," << alumnos[i].getNombre() << "," << alumnos[i].getContacto().getMail() << "," << alumnos[i].getContacto().getCelular() << endl;
    }
    
    delete[]alumnos;
    system("pause");
}