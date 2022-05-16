#pragma once
#include <iostream>
using namespace std;
class MapaDeKarnaugh {
private:
	int** matriz;
	int** mposicion;
	int cantidad1;
public:
	MapaDeKarnaugh() {
		matriz = new int* [2];
		for (int i = 0; i < 2; i++) {
			matriz[i] = new int[2];
		};

		mposicion = new int* [2];
		for (int i = 0; i < 2; i++) {
			mposicion[i] = new int[2];
		};

		cantidad1 = 0;
	}
	~MapaDeKarnaugh() {}

	int getcantidad1() { return cantidad1; }
	int** getmposicion() { return mposicion; }
	int** getmatriz() { return matriz; }
	void setmatriz(int** matriz) { this->matriz = matriz; }
	void setcantidad1(int cantidad1) { this->cantidad1 = cantidad1; }

	void generarMatrizPF() {
		//Matriz que para identificar la funcion
		mposicion[0][0] = 0; //X' ^ Y'
		mposicion[0][1] = 1; //X' ^ Y
		mposicion[1][0] = 2; //X ^ Y'
		mposicion[1][1] = 3; //X ^ Y
	}

	void calcularCantidad1() {
		for (short i = 0; i < 2; i++) {
			for (short j = 0; j < 2; j++) {
				cantidad1 += matriz[i][j];
			}
		}
	}
};
