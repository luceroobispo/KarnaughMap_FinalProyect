#pragma once
#include "Dato.h"

class Agrupamiento03
{
private:
	string funcion;
	vector<Dato*> f1;
	vector<Dato*> f2;
	vector<vector<Dato*>> f5;
public:
	Agrupamiento03(int f11, int f11x, int f11y,/**/ int f12, int f12x, int f12y,/**/ int f13, int f13x, int f13y,/**/ int f14, int f14x, int f14y,
		int f21, int f21x, int f21y,/**/ int f22, int f22x, int f22y,/**/ int f23, int f23x, int f23y,/**/ int f24, int f24x, int f24y) {

		f1 = { new Dato(f11,f11x,f11y,"X'","Y'","Z'"),new Dato(f12,f12x,f12y,"X'","Y'","Z"),new Dato(f13,f13x,f13y,"X'","Y","Z"),new Dato(f14,f14x,f14y,"X'","Y","Z'") };
		f2 = { new Dato(f21,f21x,f21y,"X","Y'","Z'"),new Dato(f22,f22x,f22y,"X","Y'","Z"),new Dato(f23,f23x,f23y,"X","Y","Z"),new Dato(f24,f24x,f24y,"X","Y","Z'") };
		f5 = { f1,f2 };
		funcion = "";
	};
	~Agrupamiento03() {};

	void buscar8(Graphics^ g) {
		Pen^ p = gcnew Pen(Color::Yellow, 5);
		//Rectangulo 4x2 = 8
		bool completo = true;
		for (int i = 0; i < f5.size(); i++)
			for (int j = 0; j < f1.size(); j++)
				if (f5[i][j]->getValor() == 0)
					completo = false;
		if (completo == true) {
			for (int i = 0; i < f5.size(); i++)
				for (int j = 0; j < f1.size(); j++)
					f5[i][j]->setValor(2);

			g->DrawRectangle(p, f5[0][0]->getX() - 10, f5[0][0]->getY() - 10, (71 * 4) + 5, (30 * 2) + 10);

			funcion = funcion + "1   ";
		}

	}
	void buscar4(Graphics^ g) {
		Pen^ p = gcnew Pen(Color::Blue, 3);

		//Cuadrado 2x2
		for (int i = 0; i < 1; i++) //cuantas vceces bajara
			for (int j = 0; j < 3; j++)//cuantas veces se movere a la derecha
				if (f5[i][j]->getValor() != 0 && f5[i + 1][j]->getValor() != 0 /**/ && f5[i][j + 1]->getValor() != 0 && f5[i + 1][j + 1]->getValor() != 0)
					if (f5[i][j]->getValor() == 1 || f5[i + 1][j]->getValor() == 1 || f5[i][j + 1]->getValor() == 1 || f5[i + 1][j + 1]->getValor() == 1) {
						f5[i][j]->setValor(2); f5[i][j + 1]->setValor(2); f5[i + 1][j]->setValor(2); f5[i + 1][j + 1]->setValor(2);

						funcion += "( ";
						if (f5[i][j]->getx() == f5[i][j + 1]->getx() && f5[i][j + 1]->getx() == f5[i + 1][j]->getx() && f5[i + 1][j]->getx() == f5[i + 1][j + 1]->getx())//comparando si tienen el mismo x (X o X')
							funcion = funcion + f5[i][j]->getx() + " ^ ";
						if (f5[i][j]->gety() == f5[i][j + 1]->gety() && f5[i][j + 1]->gety() == f5[i + 1][j]->gety() && f5[i + 1][j]->gety() == f5[i + 1][j + 1]->gety())//comparando si tienen el mismo y (Y o Y')
							funcion = funcion + f5[i][j]->gety() + " ^ ";
						if (f5[i][j]->getz() == f5[i][j + 1]->getz() && f5[i][j + 1]->getz() == f5[i + 1][j]->getz() && f5[i + 1][j]->getz() == f5[i + 1][j + 1]->getz())//comparando si tienen el mismo z (Z o Z')
							funcion = funcion + f5[i][j]->getz() + " ^ ";
						funcion[funcion.length() - 2] = ' ';
						funcion += ") V ";

						g->DrawRectangle(p, f5[i][j]->getX() - 10, f5[i][j]->getY() - 10, (71 * 2) + 10, (30 * 2) + 5);
					}
		//Cuadrado extremo ]00[
		//				   ]00[
		for (int i = 0; i < 1; i++)
			if (f5[i][0]->getValor() != 0 && f5[i][3]->getValor() != 0 && f5[i + 1][0]->getValor() != 0 && f5[i + 1][3]->getValor() != 0)
				if (f5[i][0]->getValor() == 1 || f5[i][3]->getValor() == 1 || f5[i + 1][0]->getValor() == 1 || f5[i + 1][3]->getValor() == 1) {
					f5[i][0]->setValor(2); f5[i][3]->setValor(2); f5[i + 1][0]->setValor(2); f5[i + 1][3]->setValor(2);

					funcion += "( ";
					if (f5[i][0]->getx() == f5[i][3]->getx() && f5[i][3]->getx() == f5[i + 1][0]->getx() && f5[i + 1][0]->getx() == f5[i + 1][3]->getx())//comparando si tienen el mismo x (X o X')
						funcion = funcion + f5[i][0]->getx() + " ^ ";
					if (f5[i][0]->gety() == f5[i][3]->gety() && f5[i][3]->gety() == f5[i + 1][0]->gety() && f5[i + 1][0]->gety() == f5[i + 1][3]->gety())//comparando si tienen el mismo y (Y o Y')
						funcion = funcion + f5[i][0]->gety() + " ^ ";
					if (f5[i][0]->getz() == f5[i][3]->getz() && f5[i][3]->getz() == f5[i + 1][0]->getz() && f5[i + 1][0]->getz() == f5[i + 1][3]->getz())//comparando si tienen el mismo z (Z o Z')
						funcion = funcion + f5[i][0]->getz() + " ^ ";

					funcion[funcion.length() - 2] = ' ';
					funcion += " ) V ";

					g->DrawRectangle(p, f5[i][0]->getX() - 10, f5[i][0]->getY() - 10, (71 * 1) + 10, (30 * 2) + 5);
					g->DrawRectangle(p, f5[i][3]->getX() - 10, f5[i][3]->getY() - 10, (71 * 1) + 10, (30 * 2) + 5);
				}

		//horizontal
		for (int i = 0; i < f5.size(); i++)
			if (f5[i][0]->getValor() != 0 && f5[i][1]->getValor() != 0 && f5[i][2]->getValor() != 0 && f5[i][3]->getValor() != 0)
				if (f5[i][0]->getValor() == 1 || f5[i][1]->getValor() == 1 || f5[i][2]->getValor() == 1 || f5[i][3]->getValor() == 1) {// si encuentra una fila de 4 cambia el valor de ese grupo a 2
					f5[i][0]->setValor(2); f5[i][1]->setValor(2); f5[i][2]->setValor(2); f5[i][3]->setValor(2);

					funcion += "( ";
					if (f5[i][0]->getx() == f5[i][1]->getx() && f5[i][1]->getx() == f5[i][2]->getx() && f5[i][2]->getx() == f5[i][3]->getx())//comparando si tienen el mismo x (X o X')
						funcion = funcion + f5[i][0]->getx() + " ^ ";
					if (f5[i][0]->gety() == f5[i][1]->gety() && f5[i][1]->gety() == f5[i][2]->gety() && f5[i][2]->gety() == f5[i][3]->gety())//comparando si tienen el mismo y (Y o Y')
						funcion = funcion + f5[i][0]->gety() + " ^ ";
					if (f5[i][0]->getz() == f5[i][1]->getz() && f5[i][1]->getz() == f5[i][2]->getz() && f5[i][2]->getz() == f5[i][3]->getz())//comparando si tienen el mismo z (Z o Z')
						funcion = funcion + f5[i][0]->getz() + " ^ ";

					funcion[funcion.length() - 2] = ' ';
					funcion += ") V ";

					g->DrawRectangle(p, f5[i][0]->getX() - 10, f5[i][0]->getY() - 10, (71 * 4) + 10, (30 * 1) + 5);
				}
	}
	void buscar2(Graphics^ g) {
		Pen^ p = gcnew Pen(Color::Green, 1);

		//horizontal
		for (int i = 0; i < f5.size(); i++)
			for (int j = 0; j < 3; j++)
				if (f5[i][j]->getValor() != 0 && f5[i][j + 1]->getValor() != 0) // verificamos que hay un grupo de 2 diferentes de 0
					if (f5[i][j]->getValor() == 1 || f5[i][j + 1]->getValor() == 1) {
						f5[i][j]->setValor(2); f5[i][j + 1]->setValor(2);

						funcion += "( ";
						if (f5[i][j]->getx() == f5[i][j + 1]->getx())//comparando si tienen el mismo x (X o X')
							funcion = funcion + f5[i][j]->getx() + " ^ ";
						if (f5[i][j]->gety() == f5[i][j + 1]->gety())//comparando si tienen el mismo y (Y o Y')
							funcion = funcion + f5[i][j]->gety() + " ^ ";
						if (f5[i][j]->getz() == f5[i][j + 1]->getz())//comparando si tienen el mismo z (Z o Z')
							funcion = funcion + f5[i][j]->getz() + " ^ ";

						funcion[funcion.length() - 2] = ' ';
						funcion += ") V ";

						g->DrawRectangle(p, f5[i][j]->getX() - 10, f5[i][j]->getY() - 10, (71 * 2) + 10, (30 * 1) + 5);
					}


		//vertical

		for (int j = 0; j < 1; j++)
			for (int i = 0; i < 4; i++)
				if (f5[j][i]->getValor() != 0 && f5[j + 1][i]->getValor() != 0)
					if (f5[j][i]->getValor() == 1 || f5[j + 1][i]->getValor() == 1) {
						f5[j][i]->setValor(2); f5[j + 1][i]->setValor(2);

						funcion += "( ";
						if (f5[j][i]->getx() == f5[j + 1][i]->getx())//comparando si tienen el mismo x (X o X')
							funcion = funcion + f5[j][i]->getx() + " ^ ";
						if (f5[j][i]->gety() == f5[j + 1][i]->gety())//comparando si tienen el mismo y (Y o Y')
							funcion = funcion + f5[j][i]->gety() + " ^ ";
						if (f5[j][i]->getz() == f5[j + 1][i]->getz())//comparando si tienen el mismo z (Z o Z')
							funcion = funcion + f5[j][i]->getz() + " ^ ";

						funcion[funcion.length() - 2] = ' ';
						funcion += ") V ";

						g->DrawRectangle(p, f5[j][i]->getX() - 10, f5[j][i]->getY() - 10, (71 * 1) + 10, (30 * 2) + 5);
					}

	}
	void buscarEx(Graphics^ g) {
		Pen^ p = gcnew Pen(Color::Red, 4);
		//horizontal
		for (int i = 0; i < f5.size(); i++)
			if (f5[i][0]->getValor() != 0 && f5[i][3]->getValor() != 0)
				if (f5[i][0]->getValor() == 1 || f5[i][3]->getValor() == 1) {
					f5[i][0]->setValor(2); f5[i][3]->setValor(2);

					funcion += "( ";
					if (f5[i][0]->getx() == f5[i][3]->getx())//comparando si tienen el mismo x (X o X')
						funcion = funcion + f5[i][0]->getx() + " ^ ";
					if (f5[i][0]->gety() == f5[i][3]->gety())//comparando si tienen el mismo y (Y o Y')
						funcion = funcion + f5[i][0]->gety() + " ^ ";
					if (f5[i][0]->getz() == f5[i][3]->getz())//comparando si tienen el mismo z (Z o Z')
						funcion = funcion + f5[i][0]->getz() + " ^ ";

					funcion[funcion.length() - 2] = ' ';
					funcion += " ) V ";

					g->DrawRectangle(p, f5[i][0]->getX() - 10, f5[i][0]->getY() - 10, (71 * 1) + 10, (30 * 1) + 5);
					g->DrawRectangle(p, f5[i][3]->getX() - 10, f5[i][3]->getY() - 10, (71 * 1) + 10, (30 * 1) + 5);
				}


	}
	void buscarNo(Graphics^ g) {
		Pen^ p = gcnew Pen(Color::Chocolate, 4);
		for (int i = 0; i < f5.size(); i++)
			for (int j = 0; j < f1.size(); j++)
				if (f5[i][j]->getValor() == 1) {
					funcion = funcion + "( " + f5[i][j]->getx() + " ^ " + f5[i][j]->gety() + " ^ " + f5[i][j]->getz() + ") V ";
					g->DrawRectangle(p, f5[i][j]->getX() - 10, f5[i][j]->getY() - 10, (71 * 1) + 10, (30 * 1) + 5);
				}


	}

	string getFuncion() {
		if (funcion != "")
		{
			funcion[funcion.length() - 2] = ' '; // elimino la "V" que queda despues de la busqueda de grupos y no agrupados 
		}

		return funcion;
	}
};

