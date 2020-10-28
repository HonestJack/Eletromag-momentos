#include <iostream>
#include <stdio.h>
#include <math.h>

#ifndef FITA_H
#define FITA_H


#define MAX_NUM_SUPS 200

#define PI 3.1415
#define PERMISIVIDADE 8.854187817e-012


#define V_TESTE_1 1
#define V_TESTE_2 0


class c_sup_infinitesimal{
	public:
		float  pos_x;
		float  pos_y;
		float  pos_z;
};

class c_fita{
	public:
		c_sup_infinitesimal v_sup_infinitesimal[MAX_NUM_SUPS];
		float  largura, comprimento, area;
		float  del_x, del_y;
		int div_largura, div_comprimento;
		
		void preenche_dim( float aux_larg, float aux_comp, int aux_div_larg, int aux_div_comp);
		void preenche_pos(float shift_y, float shift_x, float shift_z);
		void pede_dados();
};

class c_capacitor
{
	private:
		c_fita fita_1, fita_2;
		c_sup_infinitesimal fitas_mescladas[2*MAX_NUM_SUPS];
		
		float  A[2*MAX_NUM_SUPS][2*MAX_NUM_SUPS];
		float  L[2*MAX_NUM_SUPS][2*MAX_NUM_SUPS];
		float  V[2*MAX_NUM_SUPS];
		float  y[2*MAX_NUM_SUPS];
		float  p[2*MAX_NUM_SUPS];
		float carga_1, carga_2;
		float capacitancia;
		
		float  largura, comprimento, area;
		float  dist_x, dist_y, dist_z;
		int div_largura, div_comprimento;
		
		void mescla_fitas();
		float  distancia(int i, int j);
		
	public:
		void pede_dados();
		void monta_vetor_V();
		void monta_matriz_A();
		void monta_matriz_L();
		void encontra_vetor_y();
		void encontra_vetor_p();
		void calcula_carga();
		void calcula_capacitancia();
};

#endif
