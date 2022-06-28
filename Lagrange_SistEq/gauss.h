
#ifndef GAUSS_H
#define GAUSS_H

#include <iostream>
#include <cmath>
#include <iomanip>
#include <fstream>

using namespace std;

void menuGauss();


class Gauss {

	private:

		int n; // tamaño de la matriz cuadrada
		double** mat; // para matriz
		double* b; //  para valores independientes
		double* x; // para resolver por sust inversa
        int* per; // pivote
	public:

		void creaMatriz();
		void creaArrayValoresIndependientes();
		void ingresarDatos();
		void muestraDatos();
		void creaMatrizInverso();
		void muestraIncongnitas();
		void muestraSolucion();

		void resuelvePivot();
		void resuelveInversa();

        void liberaMemo();

};

#endif // GAUSS_H
