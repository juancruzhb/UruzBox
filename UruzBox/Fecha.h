#pragma once
#include <string>

class Fecha {
public:
    int  getDia();
    int  getMes();
    int  getAnio();
    void setDia(int dia);
    void setMes(int mes);
    void setAnio(int anio);
    Fecha(int dia, int mes, int anio);
    Fecha();
    std::string toString();
    bool operator > (Fecha fecha) {
        if (_anio > fecha._anio)return true;
        if (_mes > fecha._mes && _anio >= fecha._anio)return true;
        if (_dia > fecha._dia && _mes == fecha._mes && _anio >= fecha._anio) return true;
        return false;
    }

private:
    int _dia, _mes, _anio;
};
