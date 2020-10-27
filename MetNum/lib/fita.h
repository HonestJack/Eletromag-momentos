#include <iostream>
#include <stdio.h>
#include <math.h>

#ifndef FITA_H
#define FITA_H


#define MAX_NUM_SUPS 200

#define PI 3.1415
#define PERMISIVIDADE 8.854187817e-012


class c_sup_infinitesimal{
	public:
		double  pos_x;
		double  pos_y;
		double  pos_z;
};

class c_fita{
	public:
		c_sup_infinitesimal v_sup_infinitesimal[MAX_NUM_SUPS];
		double  largura, comprimento, area;
		double  del_x, del_y;
		int div_largura, div_comprimento;
		
		void preenche_dim( double aux_larg, double aux_comp, int aux_div_larg, int aux_div_comp);
		void preenche_pos(double shift_y, double shift_x, double shift_z);
		void pede_dados();
};

class c_capacitor
{
	private:
		c_fita fita_1, fita_2;
		c_sup_infinitesimal fitas_mescladas[2*MAX_NUM_SUPS];
		
		double  A[2*MAX_NUM_SUPS][2*MAX_NUM_SUPS];
		double  L[2*MAX_NUM_SUPS][2*MAX_NUM_SUPS];
		
		double  largura, comprimento, area;
		double  dist_x, dist_y, dist_z;
		int div_largura, div_comprimento;
		
		void mescla_fitas();
		double  distancia(int i, int j);
		
	public:
		void pede_dados();
		void monta_matriz_A();
		void monta_matriz_L();
};

#endif
