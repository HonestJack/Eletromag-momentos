
#include <stdio.h>
#include <locale.h>
#include <string>
#include <math.h>

#include "fita.h"


#define V_TESTE_1 1
#define V_TESTE_2 0

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
//	string str;
//	str  = to_string(5);
//	printf("\n\n%s\n\n", str);
	
	

	return 0;
}
