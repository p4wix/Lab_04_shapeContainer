#pragma once
#include <iostream>

class Funkcja {
public:
	Funkcja();
	virtual ~Funkcja();

	virtual float oblicz(float x) = 0;
};

class FunkcjaLiniowa : public Funkcja {
protected:
	float a;
	float b;

public:
	FunkcjaLiniowa(float, float);
	virtual ~FunkcjaLiniowa();

	float oblicz(float);
};

