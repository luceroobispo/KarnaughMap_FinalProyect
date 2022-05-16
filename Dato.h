#pragma once
#include<string>
#include <vector>
#include<iostream>
#include<conio.h>
#include<stdlib.h>
#include<string>
using namespace std;
using namespace System;
using namespace System::Drawing;

class Dato
{
private:
	int v, x, y;
	string x1, y1, z1, w1;
public:
	Dato(int v, int x, int y, string x1, string y1, string z1, string w1) {
		this->v = v;
		this->x = x;//distancia del contenedor con respecto al contenedor rosa en ancho
		this->y = y;//distancia del contenedor a esta  en alto
		this->x1 = x1;
		this->y1 = y1;
		this->z1 = z1;
		this->w1 = w1;
	};
	Dato(int v, int x, int y, string x1, string y1, string z1) {
		this->v = v;
		this->x = x;//distancia del contenedor con respecto al contenedor rosa en ancho
		this->y = y;//distancia del contenedor a esta  en alto
		this->x1 = x1;
		this->y1 = y1;
		this->z1 = z1;
	}
	~Dato() {};

	int getX() { return x; }
	int getY() { return y; }
	int getValor() { return v; }
	void setValor(int v) { this->v = v; }

	string getx() { return x1; }
	string gety() { return y1; }
	string getz() { return z1; }
	string getw() { return w1; }
	void setVariables(string x1, string y1, string z1, string w1) {
		this->x1 = x1;
		this->y1 = y1;
		this->z1 = z1;
		this->w1 = w1;
	}

};

