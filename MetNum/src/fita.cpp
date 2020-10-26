#include"fita.h"

void c_fita::preenche_dim(float aux_larg, float aux_comp, int aux_div_larg, int aux_div_comp){
	largura = aux_larg;
	comprimento = aux_comp;
	div_largura = aux_div_larg;
	div_comprimento = aux_div_comp;
	del_x = comprimento/div_comprimento;
	del_y = largura/div_largura;
	area  = (largura/div_largura) * (comprimento/div_comprimento);
}
		
void c_fita::preenche_pos( float shift_y, float shift_x){
	int i, j;
	using namespace std;
	printf("\n");
	for(i=0;i<div_largura;i++){
		printf("\n");
		for(j=0;j<div_comprimento;j++){
			v_sup_infinitesimal[i+j].pos_x = del_x*(0.5 + j) + shift_x;
			v_sup_infinitesimal[i+j].pos_y = del_y*(0.5 + i) + shift_y;
			printf("   (%.2f;%.2f)   ", v_sup_infinitesimal[i+j].pos_x, v_sup_infinitesimal[i+j].pos_y);
		}
	}
	printf("\n\n Area = %f", area);
}

