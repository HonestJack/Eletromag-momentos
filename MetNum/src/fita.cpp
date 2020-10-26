#include"fita.h"

using namespace std;

void c_fita::preenche_dim(float aux_larg, float aux_comp, int aux_div_larg, int aux_div_comp)
{
	largura = aux_larg;
	comprimento = aux_comp;
	div_largura = aux_div_larg;
	div_comprimento = aux_div_comp;
	del_x = comprimento/div_comprimento;
	del_y = largura/div_largura;
	area  = (largura/div_largura) * (comprimento/div_comprimento);
}
		
void c_fita::preenche_pos( float shift_y, float shift_x)
{
	int i, j, k=0;
	using namespace std;
	printf("\n");
	for(i=0;i<div_largura;i++){
		printf("\n");
		for(j=0;j<div_comprimento;j++){
			v_sup_infinitesimal[k].pos_x = del_x*(0.5 + j) + shift_x;
			v_sup_infinitesimal[k].pos_y = del_y*(0.5 + i) + shift_y;
			printf(" %d-(%.2f;%.2f)   ",k, v_sup_infinitesimal[k].pos_x, v_sup_infinitesimal[k].pos_y);
			k++;
		}
	}
	printf("\n\n Area = %f", area);
}

void c_capacitor::pede_dados()
{	
	cout << "Digite a largura das fitas: ";
//	scanf("%f", &largura);
	cin  >> largura;
	cout << "Digite a quantidade de subdivisões na largura da fita: ";
	cin  >> div_largura;     // y
	cout << "Digite o comprimento das fitas: ";
	cin  >> comprimento;
	cout << "Digite a quantidade de subdivisões no comprimento da fita da fita: ";
	cin  >> div_comprimento; // x
	cout << "Digite a distância y entre as fitas: ";
	cin  >> dist_y;	
	
	fita_1.preenche_dim(largura, comprimento, div_largura, div_comprimento);
	fita_1.preenche_pos(0, 0);
	
	fita_2.preenche_dim(largura, comprimento, div_largura, div_comprimento);
	fita_2.preenche_pos((dist_y+largura), 0);
	
	mescla_fitas();

}

void c_capacitor::mescla_fitas()
{
	int i;
	int num_div = div_comprimento*div_largura;
	cout << "\n";
	cout << "\n";
	cout << "\n";
	for(i=0; i<num_div; i++)
	{
		fitas_mescladas[i] = fita_1.v_sup_infinitesimal[i];
		fitas_mescladas[i+num_div] = fita_2.v_sup_infinitesimal[i];
		printf("  %d-(%.2f;%.2f)   ", i, fitas_mescladas[i].pos_x, fitas_mescladas[i].pos_y);
		printf("  %d-(%.2f;%.2f)   ", i+num_div,fitas_mescladas[i+num_div].pos_x, fitas_mescladas[i+num_div].pos_y);
		cout << "\n";
	}
	
}

float c_capacitor::distancia(int i, int j)
{
	float distancia_x = abs(fitas_mescladas[i].pos_x - fitas_mescladas[j].pos_x), 
		  distancia_y = abs(fitas_mescladas[i].pos_y - fitas_mescladas[j].pos_y);
		  
	return(sqrt(distancia_x*distancia_x + distancia_y*distancia_y));
	
	
	
}

void c_capacitor::monta_matriz_A()
{
	int i, j;
	int num_div = 2*div_comprimento*div_largura;
	
	float del_x = comprimento/div_comprimento;
	float del_y = largura/div_largura;
	
	cout << "\nMatriz A:\n";
	
	for(i=0;i<num_div;i++)
	{
		for(j=0;j<num_div;j++)
		{	
			if(i != j)
			{
				A[i][j] = (del_x*del_y) / (4*PI*PERMISIVIDADE*distancia(i, j));
			}else
			{
				A[i][j] = 0;
			}
			printf("%02f  ", A[i][j]);
		}
	cout << "\n";	
	}
}

