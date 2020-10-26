#include <stdio.h>

#define MAX_NUM_SUPS 200

class c_sup_infinitesimal{
	public:
		float pos_x;
		float pos_y;
		float pos_z;
		float A;
};

class c_fita{
	public:
		c_sup_infinitesimal v_sup_infinitesimal[MAX_NUM_SUPS];
		float largura, comprimento, area;
		float del_x, del_y;
		int div_largura, div_comprimento;
		
		void preenche_dim(float aux_larg, float aux_comp, int aux_div_larg, int aux_div_comp);
		void preenche_pos( float shift_y, float shift_x);
};

