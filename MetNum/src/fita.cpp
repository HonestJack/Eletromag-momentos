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
	area = (largura/div_largura) * (comprimento/div_comprimento);
}
		
void c_fita::preenche_pos(float  shift_y, float  shift_x, float shift_z)
{
	int i, j, k=0;
	using namespace std;
	printf("\n");
	for(i=0;i<div_largura;i++){
		printf("\n");
		for(j=0;j<div_comprimento;j++){
			v_sup_infinitesimal[k].pos_x = del_x*(0.5 + j) + shift_x;
			v_sup_infinitesimal[k].pos_y = del_y*(0.5 + i) + shift_y;
			v_sup_infinitesimal[k].pos_z = shift_z;
			printf(" %d-(%.2f;%.2f)  ",k, v_sup_infinitesimal[k].pos_x, v_sup_infinitesimal[k].pos_y);
			k++;
		}
	}
	printf("\n\n Area = %f", area);
}

void c_capacitor::pede_dados()
{	
	cout << "Digite a largura das fitas: ";
//	scanf("%f", &largura);
	cin >> largura;
	cout << "Digite a quantidade de subdivisões na largura da fita: ";
	cin >> div_largura;   // y
	cout << "Digite o comprimento das fitas: ";
	cin >> comprimento;
	cout << "Digite a quantidade de subdivisões no comprimento da fita da fita: ";
	cin >> div_comprimento; // x
	cout << "Digite a distância y entre as fitas: ";
	cin >> dist_y;
	cout << "Digite a distância z entre as fitas: ";
	cin >> dist_z;	
//	dist_z = 0; 
	
	fita_1.preenche_dim(largura, comprimento, div_largura, div_comprimento);
	fita_1.preenche_pos(0, 0, 0);
	
	fita_2.preenche_dim(largura, comprimento, div_largura, div_comprimento);
	fita_2.preenche_pos((dist_y+largura), 0, dist_z);
	
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
		printf(" %d-(%.2f;%.2f)  ", i, fitas_mescladas[i].pos_x, fitas_mescladas[i].pos_y);
		printf(" %d-(%.2f;%.2f)  ", i+num_div,fitas_mescladas[i+num_div].pos_x, fitas_mescladas[i+num_div].pos_y);
		cout << "\n";
	}
	
}

float  c_capacitor::distancia(int i, int j)
{
	float  distancia_x = abs(fitas_mescladas[i].pos_x - fitas_mescladas[j].pos_x), 
		   distancia_y = abs(fitas_mescladas[i].pos_y - fitas_mescladas[j].pos_y),
		   distancia_z = abs(fitas_mescladas[i].pos_z - fitas_mescladas[j].pos_z);
		 
	return(sqrt(distancia_x*distancia_x + distancia_y*distancia_y + distancia_z*distancia_z));
	
}

void c_capacitor::monta_matriz_A()
{
	int i, j;
	int num_div = 2*div_comprimento*div_largura;
	
	float  del_x = comprimento/div_comprimento;
	float  del_y = largura/div_largura;
	
	float  Aii = (del_y+del_x)*log(1+sqrt(2))/(2*PI*PERMISIVIDADE);
	
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
				A[i][j] = Aii;
			}
			printf(" %011.0f ", A[i][j]);
		}
	cout << "\n";	
	}
}

void c_capacitor::monta_matriz_L()
{
	int i, j, k;
	int num_div = 2*div_comprimento*div_largura;
	float  sum = 0;
	
	cout << "\nMatriz L:\n";
	for(i=0;i<num_div;i++)
	{
		for(j=0;j<num_div;j++)
		{
			if(i == j)
			{
				for(k=0;k<(j-1);k++)
				{
					sum += L[j][k]*L[j][k];
				}
				L[i][j] = sqrt(A[i][j] - sum);
				sum = 0;
			}else if(i > j)
			{
				for(k=0;k<=(j-1);k++)
				{
					sum += L[i][k]*L[j][k];
				}
				L[i][j] = (A[i][j] - sum)/L[j][j];
				sum = 0;
			}else
			{
				L[i][j] = 0;
			}	
			printf("%09.2f  ", L[i][j]);
			
		}
		cout << "\n";
	}
	cout  << "\n\n[A]*[p]=[L][Lt]*[p]=[V]";
	cout  << "\n[Lt][p]=[y], e [L][y]=[V]";
}

void c_capacitor::monta_vetor_V()
{
	int i;
	int num_div_em_uma_placa = div_comprimento*div_largura;
	
	for(i=0;i<num_div_em_uma_placa;i++)
	{
		V[i] = V_TESTE_1;
		V[i+num_div_em_uma_placa] = V_TESTE_2;
	}
}

void c_capacitor::encontra_vetor_y()
{
	int i, j;
	int num_div = 2*div_comprimento*div_largura;
	float sum = 0;
	
	cout << "\n\n Vetor y:\n";
	for(i=0;i<num_div;i++)
	{
		for(j=0;j<i;j++)
		{
			sum += y[j]*L[i][j];				
		}
		y[i] = (V[i]-sum)/L[i][i];
		sum = 0;
		cout << y[i] << ",\n";
	}
}

void c_capacitor::encontra_vetor_p()
{
	int i, j;
	int num_div = 2*div_comprimento*div_largura;
	float sum = 0;
	
	cout << "\n\n Vetor p:\n";
	for(i=(num_div-1);i>=0;i--)
	{
		for(j=i;j<=(num_div-1);j++)
		{
			sum += p[j]*L[j][i];				
		}
		p[i] = (y[i]-sum)/L[i][i];
		sum = 0;
		cout << p[i] << ",\n";
	}
}

void c_capacitor::calcula_carga()
{
	int i;
	int num_div_em_uma_placa = div_comprimento*div_largura;
	
	carga_1 = 0;
	carga_2 = 0;
	
	for(i=0;i<num_div_em_uma_placa;i++)
	{
		carga_1 += p[i]*fita_1.area;
		carga_2 += p[i + num_div_em_uma_placa]*fita_2.area;
	}
	cout << "\n\nCarga da placa 1: " << carga_1;
	cout << "\nCarga da placa 2: " << carga_2;
}

void c_capacitor::calcula_capacitancia()
{
	capacitancia = abs(carga_1/(V_TESTE_1-V_TESTE_2));
	cout << "\n\nCapacitância: " << capacitancia;
}

