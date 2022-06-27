#pragma once
class Config
{
private:
	float valorSusTipo1;
	float valorSusTipo2;
	float valorSusTipo3;

public:
	Config();
	Config(float t1, float t2, float t3);
	float getT1();
	float getT2();
	float getT3();
};

