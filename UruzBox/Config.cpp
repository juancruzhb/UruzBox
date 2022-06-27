#include "Config.h"

Config::Config()
{
}

Config::Config(float t1, float t2, float t3)
{
	valorSusTipo1 = t1;
	valorSusTipo2 = t2;
	valorSusTipo3 = t3;
}

float Config::getT1()
{
	return valorSusTipo1;
}

float Config::getT2()
{
	return valorSusTipo2;
}

float Config::getT3()
{
	return valorSusTipo3;
}

