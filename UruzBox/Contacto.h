#pragma once
#include<string>
class Contacto
{
private:
	int _celular;
	char _mail[50];

public:
	int getCelular();
	std::string getMail();
	void setCelular(int celular);
	void setMail(std::string mail);
	Contacto();
	Contacto(int celular, std::string mail);
};

