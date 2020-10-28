
#include <stdio.h>
#include <locale.h>
#include <string>
#include <math.h>

#include "fita.h"


/*
	===================
						 y
	===================  |_x 
	
*/

using namespace std;


int main(){
	setlocale(LC_ALL, "Portuguese");
	cout << "\n\nOlá Caralho\n\n";
	c_capacitor capacitor;
	
	capacitor.pede_dados();
	capacitor.monta_matriz_A();
	capacitor.monta_vetor_V();
	capacitor.monta_matriz_L();
	capacitor.encontra_vetor_y();
	capacitor.encontra_vetor_p();
	capacitor.calcula_carga();
	capacitor.calcula_capacitancia();

	return 0;
}
