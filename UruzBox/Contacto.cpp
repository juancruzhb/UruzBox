#include "Contacto.h"

Contacto::Contacto() {

};
Contacto::Contacto(int celular, std::string mail) {
	//TODO: se puede usar los set aca para tener las futuras validaciones?
	_celular = celular;
	strcpy(_mail, mail.c_str());
}


int Contacto::getCelular() {
	return _celular;
}
std::string Contacto::getMail() {
	std::string mail = _mail;
	return _mail;
}

void Contacto::setCelular(int celular) {
	//TODO: validar celular
	_celular = celular;
}
void Contacto::setMail(std::string mail) {
	//TODO: validar mail
	strcpy(_mail, mail.c_str());
}

