#include <iostream>
#include<iomanip>
#include "Presentacion.h"
#include"ReglasLogicas.h"
#include"Config.h"
#include <cstdlib>
#include"rlutil.h"


using namespace std;

ReglasLogicas _reglasLogicas;

#pragma region prototipos
int opcionesBuscar();
Fecha obtenerFechaHasta(Fecha desde);
bool nuevaConfiguracion();
void verConfiguracionActual();
Fecha presenteMes();
Fecha pideDesde();
Fecha pideHasta();
Fecha presenteAnio();
Fecha presenteSemana();
void mostrarMensaje(string mensaje, int color, int colorFondo, int x, int y);
#pragma endregion


#pragma region Menus
int Presentacion::MenuPrincipal()
{
    int opcion;
    char confirmarSalida;
    while (true) {
        rlutil::setColor(rlutil::WHITE);
        rlutil::setBackgroundColor(rlutil::LIGHTBLUE);
        system("cls");
        cout << "Menu Principal" << endl;
        cout << "--------------------------" << endl;
        cout << "1 - Ingresar Asistencia" << endl;
        cout << "2 - Gestion de Alumnos" << endl;
        cout << "3 - Cobranzas" << endl;
        cout << "4 - Listados" << endl;
        cout << "5 - Consultas" << endl;
        cout << "6 - Reportes" << endl;
        cout << "7 - Configurar" << endl;
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
            MenuCobranzas();
            break;
        case 4:
            MenuListados();
            break;
        case 5: 
        {
            MenuConsultas();
        }
            break;
        case 6:
            MenuReportes();
            break;
        case 7:
            Menuconfigurar();
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
        {
            int dni = _reglasLogicas.ingresarAlumno();
            if (dni != 0) {
                char opcion;
                //cout << endl << endl;
                string mensaje = "Se ha ingresado correctamente el alumno";
                mostrarMensaje(mensaje, 0, 2,0 , 0);
                cout << endl << endl;
                cout << "Desea ingresar el pago de la suscripcion ahora? (s/n): ";
                cin >> opcion;
                if (tolower(opcion) == 's') {
                    cobrarCuota(dni);
                }
                system("pause");
            }
            else {
                string mensaje = "No se pudo ingresar el alumno";
                mostrarMensaje(mensaje, 0, 4, 0, 0);
            }
            
        }
            break;
        case 2:
        {
            int reg = opcionesBuscar();
            if (reg >= 0) {
                Alumno alumno = _reglasLogicas.obtenerAlumno(reg);
                MenuEditarAlumno(alumno);
            }
        }
            break;
        case 3:
            eliminarAlumno();
            break;
        case 0:
            return 0;
            break;
        }
        cin.ignore();
    }

}
int Presentacion::MenuEditarAlumno(Alumno reg) {
    Alumno alumno = reg;
    system("cls");
    int opcion;
    char confirmarSalida;
    while (true) {
        system("cls");
        cout << "EDICION DE ALUMNO" << endl;
        cout << "--------------------------" << endl;
        cout << "1 EDITAR NOMBRE Y APELLIDO" << endl;
        cout << "2 EDITAR DNI" << endl;
        cout << "3 EDITAR FECHA DE NACIMIENTO" << endl;
        cout << "4 EDITAR CONTACTO" << endl;
        cout << "5 EDITAR SUSCRIPCION" << endl;
        cout << "--------------------------" << endl;
        cout << "0 - Regresar al menu principal" << endl << endl;
        cout << "Opcion: ";
        cin >> opcion;

        switch (opcion) {
        case 1:
        {
            std::string nombre, apellido;
            cout << "Nombre: ";
            cin >> nombre;
            cout << "Apellido: ";
            cin >> apellido;         
            alumno.setNombre(nombre);
            alumno.setApellido(apellido);
            _reglasLogicas.editarAlumno(alumno);
        }
            break;
        case 2:
        {
            int dni;
            cout << "DNI: ";
            cin >> dni;
            alumno.setDni(dni);
            _reglasLogicas.editarAlumno(alumno);
        }
            break;
        case 3:
        {
            int dd,mm,aa;
            cout << "DIA: ";
            cin >> dd;
            cout << "MES: ";
            cin >> mm;
            cout << "ANIO: ";
            cin >> aa;
            Fecha fecha(dd, mm, aa);
            alumno.setFechaNac(fecha);
            _reglasLogicas.editarAlumno(alumno);
        }
            break;
        case 4:
        {
            int cel;
            std::string email;
            cout << "CELULAR: ";
            cin >> cel;
            cout << "EMAIL: ";
            cin >> email;
            Contacto contacto(cel, email);
            alumno.setContacto(contacto);
            _reglasLogicas.editarAlumno(alumno);
        }
        break;
        case 5:
        {
            int sus;
            cout << "Suscripcion:" << endl;
            cout << " 1. 2 veces por semana" << endl;
            cout << " 2. 3 veces por semana" << endl;
            cout << " 3. Libre" << endl;
            cin >> sus;
            alumno.setSuscripcion(sus);
            _reglasLogicas.editarAlumno(alumno);
        }
        break;

        case 0:
            cout << "Opcion: ";
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
    
    int reg = opcionesBuscar();
    if (reg >= 0) {
    Alumno alumno = _reglasLogicas.obtenerAlumno(reg);
    if (_reglasLogicas.ingresarAsistencia(alumno)) {
        cout << endl << endl;
        string mensaje = "Se ha ingresado la asistencia con exito";
        mostrarMensaje(mensaje, 0, 2, 0, 500);
        cout << endl << endl;
        system("pause");
        }
    }
    return 0;
}
int Presentacion::MenuReportes() {
    system("cls");
    int opcion;
    char confirmarSalida;
    while (true) {
        system("cls");
        cout << "Menu Reportes" << endl;
        cout << "--------------------------" << endl;
        cout << "1 - Alumnos por fecha de ingreso" << endl;
        cout << "2 - Asistencias por fecha" << endl;
        cout << "3 - Pagos realizados por fecha" << endl;
        cout << "5 - Exportar alumnos" << endl;
        cout << "0 - Regresar al menu principal" << endl << endl;
        cout << "Opcion: ";
        cin >> opcion;

        switch (opcion) {
        case 1:
        {
            subMenuRangoFechaAlumnos();

        }
            break;
        case 2:
        {
            subMenuRangoFechaAsistencias();

        }
            
            break;
        case 3:
        {
            subMenuRangoFechaPagos();
        }
            
            break;
        case 4:
            exportarAlumnos();
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
        cout << "2 - Pagos atrasados" << endl;
        cout << "0 - Regresar al menu principal" << endl << endl;
        cout << "Opcion: ";
        cin >> opcion;

        switch (opcion) {
        case 1:
            cobrarCuota();
            break;
        case 2:
            mostrarCuotasAtrasadas();
            break;
        case 0:
            cout << "Opcion: ";
            return 0;
            break;
        }
        cin.ignore();
    }
}
int Presentacion::MenuConsultas() {
    system("cls");
    int opcion;
    char confirmarSalida;
    while (true) {
        system("cls");
        cout << "Menu Consultas" << endl;
        cout << "--------------------------" << endl;
        cout << "1 - Ficha de Alumno" << endl;
        cout << "2 - Asistencias por Alumno" << endl;
        cout << "3 - Pagos por alumno" << endl;
        cout << "0 - Regresar al menu principal" << endl << endl;
        cout << "Opcion: ";
        cin >> opcion;

        switch (opcion) {
        case 1:
            {
                int reg = opcionesBuscar();
                if (reg >= 0) {
                    ConsultaAlumno(reg);
                }
            }
            break;

        case 2:
        {
            int reg = opcionesBuscar();
            if (reg >= 0) {
                mostrarAsistencias(reg);
            }
        }
            break;
        case 3:
        {
            int reg = opcionesBuscar();
            if (reg >= 0) {
                mostrarPagos(reg);
            }
        }
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
        return;
    }
    for (int i = 0; i < cantidad; i++) {
        alumnos[i] = _reglasLogicas.obtenerAlumno(i);
    }
    system("cls");
    cout << left;
    cout << std::setfill(' ') << std::setw(136);
    cout << setw(4) << "ID";
    cout << setw(12) << "DNI";
    cout << setw(15) << "APELLIDO";
    cout << setw(15) << "NOMBRE";
    cout << setw(10) << "EDAD";
    cout << setw(25) << "EMAIL";
    cout << setw(15) << "CELULAR";
    cout << setw(20) << "MIEMBRO DESDE";
    cout << setw(20) << "SUSCRIPCION" << endl;

    cout << "-------------------------------------------------------------------------------------------------------------------------------------------" << endl;

    for (int i = 0; i < cantidad; i++) {
        if (alumnos[i].getActivo()) {
            cout << left;
            cout << std::setfill(' ') << std::setw(136);
            cout << setw(4) << alumnos[i].getId();
            cout << setw(12) << alumnos[i].getDni();
            cout << setw(15) << alumnos[i].getApellido();
            cout << setw(15) << alumnos[i].getNombre();
            cout << setw(10) << alumnos[i].getEdad();
            cout << setw(25) << alumnos[i].getContacto().getMail();
            cout << setw(15) << alumnos[i].getContacto().getCelular();
            cout << setw(20) << alumnos[i].mostrarFechaAlta();
            cout << setw(20) << alumnos[i].getSuscripcionString();

            cout << endl;
        }
    }
    cout << endl << endl << endl << endl;

    delete []alumnos;

   system("pause");
   system("cls");
}
void Presentacion::ConsultaAlumno(int reg) {
    Alumno alumno = _reglasLogicas.obtenerAlumno(reg);

    system("cls");
    cout << std::setfill(' ') << std::setw(122);
    cout << left;
    cout << setw(4) << "ID";
    cout << setw(12) << "DNI";
    cout << setw(15) << "APELLIDO";
    cout << setw(15) << "NOMBRE";
    cout << setw(6) << "EDAD";
    cout << setw(25) << "EMAIL";
    cout << setw(15) << "CELULAR";
    cout << setw(15) << "MIEMBRO DESDE";
    cout << setw(15) << "SUSCRIPCION" << endl;

    cout << "---------------------------------------------------------------------------------------------------------------------------" << endl;
    cout << left;
    cout << std::setfill(' ') << std::setw(122);
    cout << setw(4) << alumno.getId();
    cout << setw(12) << alumno.getDni();
    cout << setw(15) << alumno.getApellido();
    cout << setw(15) << alumno.getNombre();
    cout << setw(6) << alumno.getEdad();
    cout << setw(25) << alumno.getContacto().getMail();
    cout << setw(15) << alumno.getContacto().getCelular();
    cout << setw(15) << alumno.mostrarFechaAlta();
    cout << setw(15) << alumno.getSuscripcionString();

    cout << endl;
    cout << endl << endl << endl << endl;


    system("pause");
    system("cls");
}
void Presentacion::mostrarAsistencias(int Nreg) {
   
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
    cout << std::setfill(' ') << std::setw(51);
    cout << left;
    cout << setw(6) << "ID";
    cout << setw(15) << "APELLIDO";
    cout << setw(15) << "NOMBRE";
    cout << setw(15) << "FECHA" << endl;
    cout << std::setfill(' ') << std::setw(51);
    cout << "-------------------------------------------------------" << endl;
    if (Nreg >= 0) {
        Alumno seleccionado = _reglasLogicas.obtenerAlumno(Nreg);
        for (int i = 0; i < cantidadAsis; i++) {
            for (int j = 0; j < cantidadAlum; j++) {
                if (aux[i].getIdAlumno() == reg[j].getId() && reg[j].getId()==seleccionado.getId()) {
                    cout << left;
                    cout << setw(6) << aux[i].getId();
                    cout << setw(15) << reg[j].getApellido();
                    cout << setw(15) << reg[j].getNombre();
                    cout << setw(15) << aux[i].getFecha().toString();
                    cout << endl;
                }
            }
        }
        cout << endl << endl << endl << endl;
        delete[]aux;
        delete[]reg;
        system("pause");
        system("cls");
        return;
    }

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
void Presentacion::cobrarCuota(int Ndni) {
    //TODO: si el DNI no existe pedir nuevamente los datos o 0 para salir
    system("cls");
    char opcion;
    int dni = Ndni;
    int id;
    float importe;
    if(dni == 0){
        cout << "Ingrese el DNI: ";
        cin >> dni;
        while (!_reglasLogicas.existeAlumno(dni)) {
            cout << "No se ha encontrado el DNI en la base de datos. Ingreselo nuevamente (0 para salir):";
            cin >> dni;
            if (dni == 0) return;
        }
    }

    Alumno alumno = _reglasLogicas.obtenerAlumno(-1, dni);
    id = alumno.getId();
    importe = _reglasLogicas.obtenerImporte(alumno.getSuscripcion());

    cout << "Precio correspondiente a la suscripcion: " << importe << endl;
    Pagos ultimoPago = _reglasLogicas.obtenerUltimoPago(id);
    //ultimoPago.getIdAlumno() == id)
    if (true) {
        Fecha desde = ultimoPago.getFechaHasta();
        Fecha hasta = obtenerFechaHasta(desde);
        cout << left;
        cout << setw(15) << "APELLIDO";
        cout << setw(15) << "NOMBRE";
        cout << setw(15) << "MONTO";
        cout << setw(15) << "DESDE";
        cout << setw(15) << "HASTA" << endl;
        cout << "-------------------------------------------------------" << endl;
        cout << left;
        cout << setw(12) <<alumno.getApellido();
        cout << setw(15) <<alumno.getNombre();
        cout << setw(15) << importe;
        cout << setw(15) <<desde.toString();
        cout << setw(15) << hasta.toString();
        cout << endl << endl;
        cout << "Desea ingresar el pago? (s/n): ";
            cin >> opcion;
            if (tolower(opcion) == 's') {
                if (_reglasLogicas.ingresarPago(alumno.getId(), importe, desde, hasta)) {
                    cout << endl;
                    cout << "Se ha ingresado el pago con exito" << endl << endl;
               }
            }
    }
    system("pause");
}
void Presentacion::mostrarPagos(int Nreg) {
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
    cout << std::setfill(' ') << std::setw(85);
    cout << left;
    cout << setw(10) << "RECIBO";
    cout << setw(15) << "APELLIDO";
    cout << setw(15) << "NOMBRE";
    cout << setw(15) << "MONTO";
    cout << setw(15) << "DESDE";
    cout << setw(15) << "HASTA" << endl;


    cout << "--------------------------------------------------------------------------------------" << endl;

    if (Nreg >= 0) {
        Alumno seleccionado = _reglasLogicas.obtenerAlumno(Nreg);
        for (int i = 0; i < cantidadCobros; i++) {
            for (int j = 0; j < cantidadAlum; j++) {
                if (aux[i].getIdAlumno() == reg[j].getId() && reg[j].getId() == seleccionado.getId()) {
                    cout << std::setfill(' ') << std::setw(85);
                    cout << left;
                    cout << setw(10) << aux[i].getId();
                    cout << setw(12) << reg[j].getApellido();
                    cout << setw(15) << reg[j].getNombre();
                    cout << setw(15) << aux[j].getImporte();
                    cout << setw(15) << aux[i].getFechaDesde().toString();
                    cout << setw(15) << aux[i].getFechaHasta().toString();
                    cout << endl;
                }
            }
        }
        cout << endl << endl << endl << endl;
        delete[]aux;
        delete[]reg;
        system("pause");
        system("cls");
        return;
    }

    for (int i = 0; i < cantidadCobros; i++) {
        for (int j = 0; j < cantidadAlum; j++) {
            if (aux[i].getIdAlumno() == reg[j].getId()) {
                cout << left;
                cout << setw(10) << aux[i].getId();
                cout << setw(12) << reg[j].getApellido();
                cout << setw(15) << reg[j].getNombre();
                cout << setw(15) << aux[j].getImporte();
                cout << setw(15) << aux[i].getFechaDesde().toString();
                cout << setw(15) << aux[i].getFechaHasta().toString();
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
void Presentacion::mostrarCuotasAtrasadas() {
    int size = _reglasLogicas.cantidadDeAlumnos();

    Deudor* deudores = new Deudor[size];

    if (deudores == nullptr) {
        cout << endl;
        cout << "Error al mostrar los alumnos" << endl << endl;
        return;
    }

    for (int i = 0; i < size; i++) {
        deudores[i] = _reglasLogicas.obtenerDeudor(i);
    }

    system("cls");

    cout << left;
    cout << std::setfill(' ') << std::setw(85);
    cout << setw(8) << "RECIBO";
    cout << setw(15) << "FECHA";
    cout << setw(12) << "   DNI";
    cout << setw(15) << "APELLIDO";
    cout << setw(15) << "NOMBRE";
    cout << setw(20) << "DIAS ATRASADOS" << endl;

    cout << std::setfill(' ') << std::setw(85);

    cout << "------------------------------------------------------------------------------------------" << endl;


    for (int i = 0; i < size; i++) {
        if (deudores[i].getDeuda() && deudores[i].getActivo()) {
            cout << left;
            cout << std::setfill(' ') << std::setw(85);
            cout << setw(8) << deudores[i].getIdPago();
            cout << setw(15) <<deudores[i].getUltimoPago().toString();
            cout << setw(12) << deudores[i].getDni();
            cout << setw(15) << deudores[i].getApellido();
            cout << setw(15) << deudores[i].getNombre();
            cout << setw(30) << deudores[i].getDiasAtrasado();

            cout << endl;
        }
    }
    cout << endl << endl << endl << endl;

    delete[]deudores;

    system("pause");
    system("cls");

}
int Presentacion::Menuconfigurar() {
    system("cls");
    int opcion;
    char confirmarSalida;
    while (true) {
        system("cls");
        cout << "CONFIGURACION" << endl;
        cout << "--------------------------" << endl;
        cout << "1 - Modificar valores de la cuota" << endl;
        cout << "2 - Ver valor actuales" << endl;
        //cout << "3 - Eliminar Alumno" << endl;
        //cout << "--------------------------" << endl;
        cout << "0 - Regresar al menu principal" << endl << endl;
        cout << "Opcion: ";
        cin >> opcion;
        
        switch (opcion) {
        case 1:
        {
            nuevaConfiguracion();
        }
                    
            break;
        case 2:
        {
            verConfiguracionActual();
        }

        break;
        case 0:
            cout << "Opcion: ";
            return 0;
            break;
        }
        cin.ignore();
    }
}
void Presentacion::exportarAlumnos() {
    //TODO: exportar a csv
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
void Presentacion::eliminarAlumno() {
    system("cls");

    int reg = opcionesBuscar();
    if (reg >= 0) {
        Alumno alumno = _reglasLogicas.obtenerAlumno(reg);
        if (_reglasLogicas.eliminarAlumno(alumno)){
            cout<<endl<<"Se ha eliminado el alumno correctamente";
        }

        system("pause");
    }

}
void Presentacion::reporteAlumnosFecha(Fecha desde, Fecha hasta) {
    int contador = 0;
    int cantidad = _reglasLogicas.cantidadDeAlumnos();
    Alumno* alumnos = new Alumno[cantidad];
    if (alumnos == nullptr) {
        cout << endl;
        cout << "Error al mostrar los alumnos" << endl << endl;
        return;
    }
    for (int i = 0; i < cantidad; i++) {
        alumnos[i] = _reglasLogicas.obtenerAlumno(i);
    }
    system("cls");

    cout << left;
    cout << std::setfill(' ') << std::setw(122);
    cout << setw(4) << "ID";
    cout << setw(12) << "   DNI";
    cout << setw(15) << "APELLIDO";
    cout << setw(15) << "NOMBRE";
    cout << setw(6) << "EDAD";
    cout << setw(25) << "      EMAIL";
    cout << setw(15) << "CELULAR";
    cout << setw(15) << "MIEMBRO DESDE";
    cout << setw(15) << "SUSCRIPCION" << endl;

    cout << "----------------------------------------------------------------------------------------------------------------------------" << endl;
    
    for (int i = 0; i < cantidad; i++) {
        if (alumnos[i].getActivo() && (alumnos[i].getFechaAlta()>=desde && alumnos[i].getFechaAlta()<=hasta)) {
            cout << left;
            cout << std::setfill(' ') << std::setw(122);
            cout << setw(4) << alumnos[i].getId();
            cout << setw(12) << alumnos[i].getDni();
            cout << setw(15) << alumnos[i].getApellido();
            cout << setw(15) << alumnos[i].getNombre();
            cout << setw(6)  << alumnos[i].getEdad();
            cout << setw(25) << alumnos[i].getContacto().getMail();
            cout << setw(15) << alumnos[i].getContacto().getCelular();
            cout << setw(15) << alumnos[i].mostrarFechaAlta();
            cout << setw(15) << alumnos[i].getSuscripcionString();
            contador++;
            cout << endl;
        }
    }
    cout << "TOTAL: " << contador;
    cout << endl << endl << endl << endl;
 
    delete[]alumnos;

    system("pause");
    system("cls");
}
void Presentacion::reportePagosFecha(Fecha desde, Fecha hasta) {
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
    cout << std::setfill(' ') << std::setw(70);
    cout << setw(10) << "RECIBO";
    cout << setw(15) << "APELLIDO";
    cout << setw(15) << "NOMBRE";
    cout << setw(15) << "MONTO";
    cout << setw(15) << "FECHA" << endl;


    cout << "------------------------------------------------------------------------" << endl;

    for (int i = 0; i < cantidadCobros; i++) {
        for (int j = 0; j < cantidadAlum; j++) {
            if (aux[i].getIdAlumno() == reg[j].getId() && (aux[i].getFecha() >= desde && aux[i].getFecha() <= hasta)) {
                cout << left;
                cout << std::setfill(' ') << std::setw(70);
                cout << setw(10) << aux[i].getId();
                cout << setw(15) << reg[j].getApellido();
                cout << setw(15) << reg[j].getNombre();
                cout << setw(15) << aux[j].getImporte();
                cout << setw(15) << aux[i].getFecha().toString();
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
void Presentacion::reporteAsistenciasFecha(Fecha desde, Fecha hasta) {

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
    cout << std::setfill(' ') << std::setw(51);
    cout << setw(6) << "ID";
    cout << setw(15) << "APELLIDO";
    cout << setw(15) << "NOMBRE";
    cout << setw(15) << "FECHA" << endl;

    cout << "-------------------------------------------------------" << endl;

    for (int i = 0; i < cantidadAsis; i++) {
        for (int j = 0; j < cantidadAlum; j++) {
            if (aux[i].getIdAlumno() == reg[j].getId() && (aux[i].getFecha() >= desde && aux[i].getFecha() <= hasta)) {
                cout << std::setfill(' ') << std::setw(51);
                cout << left;
                cout << setw(6) << aux[i].getId();
                cout << setw(12) << reg[j].getApellido();
                cout << setw(15) << reg[j].getNombre();
                cout << setw(15) << aux[i].getFecha().toString();
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
int Presentacion::subMenuRangoFechaAlumnos() {
    system("cls");
    int opcion;
    char confirmarSalida;
    while (true) {
        cout << "Escoja el rango de fechas" << endl;
        cout << "--------------------------" << endl;
        cout << "1 - Presente semana" << endl;
        cout << "2 - Presente Mes" << endl;
        cout << "3 - Presente Anio" << endl;
        cout << "4 - Ingresar rango de fechas" << endl;
        cout << "--------------------------" << endl;
        cout << "0 - Volver al menu principal" << endl << endl;

        cout << "Opcion: ";
        cin >> opcion;

        switch (opcion) {
        case 1:
        {
            Fecha desde = presenteSemana();
            Fecha hasta;
            reporteAlumnosFecha(desde, hasta);
        }

            break;
        case 2:
        {
            Fecha desde = presenteMes();
            Fecha hasta;
            reporteAlumnosFecha(desde, hasta);
        }
            break;
        case 3:
        {
            Fecha desde = presenteAnio();
            Fecha hasta;
            reporteAlumnosFecha(desde, hasta);
        }
            break;
        case 4:
        {
            Fecha desde = pideDesde();
            Fecha hasta = pideDesde();
            reporteAlumnosFecha(desde, hasta);
        }
        break;
        case 0:
            cout << "Opcion: ";
            return 0;
            break;
        }
        cin.ignore();
    }

}
int Presentacion::subMenuRangoFechaPagos() {
    system("cls");
    int opcion;
    char confirmarSalida;
    while (true) {
        cout << "Escoja el rango de fechas" << endl;
        cout << "--------------------------" << endl;
        cout << "1 - Presente semana" << endl;
        cout << "2 - Presente Mes" << endl;
        cout << "3 - Presente Anio" << endl;
        cout << "4 - Ingresar rango de fechas" << endl;
        cout << "--------------------------" << endl;
        cout << "0 - Volver al menu principal" << endl << endl;

        cout << "Opcion: ";
        cin >> opcion;

        switch (opcion) {
        case 1:
        {
            Fecha desde = presenteSemana();
            Fecha hasta;
            reportePagosFecha(desde, hasta);
        }

            break;
        case 2:
        {
            Fecha desde = presenteMes();
            Fecha hasta;
            reportePagosFecha(desde, hasta);
        }
        break;
        case 3:
        {
            Fecha desde = presenteAnio();
            Fecha hasta;
            reportePagosFecha(desde, hasta);
        }
            break;
        case 4:
        {
            Fecha desde = pideDesde();
            Fecha hasta = pideDesde();
            reportePagosFecha(desde, hasta);
        }
        break;
        case 0:
            cout << "Opcion: ";
            return 0;
            break;
        }
        cin.ignore();
    }

}
int Presentacion::subMenuRangoFechaAsistencias() {
    system("cls");
    int opcion;
    char confirmarSalida;
    while (true) {
        cout << "Escoja el rango de fechas" << endl;
        cout << "--------------------------" << endl;
        cout << "1 - Presente semana" << endl;
        cout << "2 - Presente Mes" << endl;
        cout << "3 - Presente Anio" << endl;
        cout << "4 - Ingresar rango de fechas" << endl;
        cout << "--------------------------" << endl;
        cout << "0 - Volver al menu principal" << endl << endl;

        cout << "Opcion: ";
        cin >> opcion;

        switch (opcion) {
        case 1:
        {
            Fecha desde = presenteSemana();
            Fecha hasta;
            reporteAsistenciasFecha(desde, hasta);
        }

            break;
        case 2:
        {
            Fecha desde = presenteMes();
            Fecha hasta;
            reporteAsistenciasFecha(desde, hasta);
        }
        break;
        case 3:
        {
            Fecha desde = presenteAnio();
            Fecha hasta;
            reporteAsistenciasFecha(desde, hasta);
        }
            break;
        case 4:
        {
            Fecha desde = pideDesde();
            Fecha hasta = pideHasta();
            reporteAsistenciasFecha(desde, hasta);
        }
        break;
        case 0:
            cout << "Opcion: ";
            return 0;
            break;
        }
        cin.ignore();
    }

}


int opcionesBuscar() {
    system("cls");
    int opcion, dni;
    std::string apellido;
    cout << "¿Como desea buscar?" << endl;
    cout << "1 - Por DNI" << endl;
    cout << "2 - Por APELLIDO" << endl;
    cout << "Opcion: ";
    cin >> opcion;
    if (opcion == 1) {
        system("cls");
        cout << "Ingrese el DNI: ";
        cin >> dni;
        while (!_reglasLogicas.existeAlumno(dni)) {
            string mensaje = "EL DNI INGRESADO NO SE ENCUENTRA EN EL REGISTRO";
            mostrarMensaje(mensaje, 0, 4, 0, 500);
            cout << "Ingrese el DNI (0) para salir: ";
            cin >> dni;
            if (dni == 0) return -2;
        }
        return _reglasLogicas.obtenerRegistroAlumnoPorDni(dni);
    }
    else if (opcion == 2) {
        cout << "Apellido: ";
        cin >> apellido;
        while (!_reglasLogicas.existeAlumnoPorApellido(apellido)) {
            string mensaje = "EL APELLIDO INGRESADO NO SE ENCUENTRA EN EL REGISTRO";
            mostrarMensaje(mensaje, 0, 4, 0, 500);
            cout << "Ingrese el apellido (0) para salir: ";
            cin >> apellido;
            if (apellido.length() == 1) {
                int op = atoi(apellido.c_str());
                if (op == 0) return - 2;
            }
        }
        Alumno seleccionado = _reglasLogicas.obtenerAlumnoConApellidoRepetido(apellido);
        cout << endl << endl;
        cout << "Ha seleccionado: " << seleccionado.getApellido() << ", " << seleccionado.getNombre() << endl;
        system("pause");
        return _reglasLogicas.obtenerRegistroAlumnoPorDni(seleccionado.getDni());
    }
}
Fecha obtenerFechaHasta(Fecha desde) {
    Fecha hasta;
    int dd = desde.getDia();
    int mm = desde.getMes();
    int aa = desde.getAnio();

    if (dd > 28 && mm == 1) {
        hasta.setDia(1);
        hasta.setMes(3);
        hasta.setAnio(aa);
        return hasta;
    }
    if (dd == 31 && (mm == 1 || mm == 3 || mm == 5 || mm == 8 || mm == 10)){
        hasta.setDia(1);
        hasta.setMes(mm + 2);
        hasta.setAnio(aa);
        return hasta;
    }
    if (mm == 12) {
        hasta.setDia(desde.getDia());
        hasta.setMes(1);
        hasta.setAnio(desde.getAnio() + 1);
        return hasta;
    }
    hasta.setAnio(desde.getAnio());
    hasta.setMes(desde.getMes() + 1);
    hasta.setDia(desde.getDia());
    return hasta;

}
bool nuevaConfiguracion() {
    float tipo1, tipo2, tipo3;
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
        system("pause");
        return true;
    }
    cout << "NO SE HAN PODIDO APLICAR LOS CAMBIOS" << endl << endl;
    system("pause");
}
void verConfiguracionActual() {
    int size = _reglasLogicas.cantidadConfig();
    Config* actual = new Config[size];
    if (actual == nullptr)return;
    for (int i = 0; i < size; i++) {
        actual[i] = _reglasLogicas.obtenerConfig(i);
    }
    system("cls");
    cout << left;
    cout << setw(20) << "2 VECES POR SEMANA";
    cout << setw(20) << "3 VECES POR SEMANA";
    cout << setw(20) << "       LIBRE      " << endl;

    cout << "-------------------------------------------------------" << endl;

    for (int i = 0; i < size; i++) {
         cout << left;
         cout << setw(20) << actual[i].getT1();
         cout << setw(20) << actual[i].getT2();
         cout << setw(20) << actual[i].getT3();
         cout << endl;

    }

    delete[]actual;
    system("pause");
}
Fecha presenteSemana() {
    Fecha actual;
    int dia = actual.getDia();
    int mes = actual.getMes();
    int anyo = actual.getAnio();
    int A = (14 - mes) / 12;
    int Y = anyo - A;
    int M = mes + (12 * A) - 2;
    int diaSemana;

    if (anyo >= 1582)       /// Inicio del calendario Gregoriano
        diaSemana = (dia + Y + Y / 4 - Y / 100 + Y / 400 + (31 * M) / 12) % 7;

    else        /// calendario Juliano
        diaSemana = (5 + dia + Y + Y / 4 + (31 * M) / 12) % 7;

    if (diaSemana > 0) diaSemana--;
    else  diaSemana = 6;

    int dd = actual.getDia();
    switch (diaSemana) {

    case 0: ; break;
    case 1:dd = dd-1 ; break;
    case 2:dd = dd-2 ; break;
    case 3:dd = dd - 3; break;
    case 4:dd = dd - 4; break;
    case 5:dd = dd - 5; break;
    case 6:dd = dd - 6; break;
    }

    Fecha fecha(dd, actual.getMes(), actual.getAnio());
    return fecha;
}
Fecha presenteMes() {
    Fecha actual;
    Fecha aux;
    if (actual.getMes() == 1) {
        aux.setAnio(actual.getAnio() - 1);
        aux.setMes(12);
        aux.setDia (1);
        return aux;
    }
    Fecha fecha(1, actual.getMes(), actual.getAnio());
    return fecha;
}
Fecha presenteAnio() {
    Fecha actual;
    Fecha fecha(1, 1, actual.getAnio());
    return fecha;
}
Fecha pideDesde() {
    int dd, mm, aa;
    cout << "Desde dia: ";
    cin >> dd;
    cout << endl;

    cout << "Desde Mes: ";
    cin >> mm;
    cout << endl;

    cout << "Desde Anio: ";
    cin >> aa;
    cout << endl;
    Fecha desde(dd, mm, aa);
    return desde;
}
Fecha pideHasta() {
    int dd, mm, aa;
    cout << "Hasta dia: ";
    cin >> dd;
    cout << endl;

    cout << "hasta Mes: ";
    cin >> mm;
    cout << endl;

    cout << "Hasta anio: ";
    cin >> aa;

    Fecha hasta(dd, mm, aa);
    return hasta;
}
void mostrarMensaje(string mensaje, int color, int colorFondo, int x, int y) {
    rlutil::saveDefaultColor();
    rlutil::locate(x, y);
    rlutil::setColor(color);
    rlutil::setBackgroundColor(colorFondo);
    cout << endl << endl;
    cout << mensaje << endl << endl;
    rlutil::resetColor();
}
