#include "Function_3.h"

Funkcja::Funkcja() {
	std::cout << "ctor Funkcja" << std::endl;
}

Funkcja::~Funkcja() {
	std::cout << "dtor Funkcja" << std::endl;
}

FunkcjaLiniowa::FunkcjaLiniowa(float a, float b) {
	this->a = a;
	this->b = b;
	std::cout << "ctor FunkcjaLiniowa" << std::endl;
}

FunkcjaLiniowa::~FunkcjaLiniowa() {
	std::cout << "dtor FunkcjaLiniowa" << std::endl;
}

float FunkcjaLiniowa::oblicz(float x) {
	return (a * x + b);
}