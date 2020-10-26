#include <iostream>
#include <locale.h>
#include <stdio.h>
#include <string>

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
	c_fita fita_1, fita_2;
	float largura, comprimento, area;
	float dist_x, dist_y, dist_z;
	int div_largura, div_comprimento;
	
	cout << "Digite a largura das fitas: ";
	cin  >> largura;
	cout << "Digite a quantidade de subdivisões na largura da fita: ";
	cin  >> div_largura;     // y
	cout << "Digite o comprimento das fitas: ";
	cin  >> comprimento;
	cout << "Digite a quantidade de subdivisões no comprimento da fita da fita: ";
	cin  >> div_comprimento; // x
	cout << "Digite a distância y entre as fitas: ";
	cin  >> dist_y;
	
//	string str;
//	str  = to_string(5);
//	printf("\n\n%s\n\n", str);
	
	fita_1.preenche_dim(largura, comprimento, div_largura, div_comprimento);
	fita_1.preenche_pos(0, 0);
	
	fita_2.preenche_dim(largura, comprimento, div_largura, div_comprimento);
	fita_2.preenche_pos((dist_y+largura), 0);



	return 0;
}
