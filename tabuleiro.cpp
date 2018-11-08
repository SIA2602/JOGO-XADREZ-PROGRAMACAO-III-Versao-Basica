#include "tabuleiro.h"
#include <iostream>



/*bool Tabuleiro :: roque(int pos_final_i, int pos_final_j){

	if(_rei_branco.getNjogadas() == 0 && pos_final_i == 7 && pos_final_j == 6 && getMatriz(7, 5) == "0" && getMatriz(7, 6) == "0" && _rei_branco.getNjogadas() == 0 ){//roque menor pecas branca
		setMatriz(pos_final_i, pos_final_j, getMatriz(_rei_branco.posicao_inicial_i(), _rei_branco.posicao_inicial_j()));
		setMatriz(_rei_branco.posicao_inicial_i(), _rei_branco.posicao_inicial_j(), "0");
		_rei_branco.inicializa_posicao(pos_final_i, pos_final_j);
		_rei_branco.getNjogadas() ;
		setMatriz(0, 5, getMatriz(0, 7));
		setMatriz(0, 7, "0");
		_torres_brancas[0].inicializa_posicao(0, 5);
		_torres_brancas[0].setNjogadas();
		return true;
	}

	if(_rei_branco.getNjogadas() == 0 && pos_final_i == 7 && pos_final_j == 2 && getMatriz(7, 1) == "0" && getMatriz(7,2) == "0" && getMatriz(7, 3) == "0" && _torres_brancas[1].getNjogadas() == 0) {//roque maior pecas pretas		_i, pos_atual_j));
		setMatriz(pos_final_i, pos_final_j,getMatriz(_rei_branco.posicao_inicial_i(), _rei_branco.posicao_inicial_j()));
		setMatriz(_rei_branco.posicao_inicial_i(), _torres_brancas[1].posicao_inicial_j(), "0");
		_rei_branco.inicializa_posicao(pos_final_i, pos_final_j);
		_rei_branco.getNjogadas() ;
		setMatriz(7, 3,getMatriz(7, 0));
		setMatriz(7, 0, "0");
		_torres_brancas[1].inicializa_posicao(7, 3);
		_torres_brancas[1].setNjogadas();
		return true;
	}


	if(_rei_preto.getNjogadas() == 0 && pos_final_i == 0 && pos_final_j == 6 && getMatriz(0, 5) == "0" && getMatriz(0, 6) == "0" && _torres_pretas[0].getNjogadas() == 0) {//roque menor pecas branca
		setMatriz(pos_final_i, pos_final_j, getMatriz(_rei_preto.posicao_inicial_i(), _rei_preto.posicao_inicial_j()));
		setMatriz(_rei_preto.posicao_inicial_i(), _rei_preto.posicao_inicial_j(), "0");
		_rei_preto.inicializa_posicao(pos_final_i, pos_final_j);
		_rei_preto.setNjogadas();
		setMatriz(0, 5, getMatriz(0, 7));
		setMatriz(0, 7, "0");
		_torres_pretas[0].inicializa_posicao(0, 5);
		_torres_pretas[0].setNjogadas();
		return true;
	}

	if(_rei_preto.getNjogadas() == 0 && pos_final_i == 0 && pos_final_j == 2 && getMatriz(0, 1) == "0" && getMatriz(0,2) == "0" && getMatriz(0, 3) == "0" && _torres_pretas[1].getNjogadas() == 0) {//roque maior pecas bramcas		
		setMatriz(pos_final_i, pos_final_j, getMatriz(_rei_preto.posicao_inicial_i(), _rei_preto.posicao_inicial_j()));
		setMatriz(_rei_preto.posicao_inicial_i(), _rei_preto.posicao_inicial_j(), "0");
		_rei_preto.inicializa_posicao(pos_final_i, pos_final_j);
		_torres_pretas[1].setNjogadas() ;
		setMatriz(0, 3, getMatriz(0, 0));
		setMatriz(0, 0, "0");
		_torres_pretas[1].inicializa_posicao(0, 3);
		_torres_pretas[0].setNjogadas();
		return true;

	}
	return false;


}*/

/*
bool xeque(){

}


verificando_xeque_TorreErainha_(int pos_atual_i, int pos_atual_j, int pos_final_i, int pos_final_j)
{


	
		int i = rei.posicao_inicial_i();
		int j = rei.posicao_inicial_j();;

		while(j < 7)
		{			
			if(getMatriz(i, j) != "0")
			{
				if(cor == "P"){
					if(getMatriz(i, j) == "RB" || getMatriz(i, j) == "TR"){//a primeira peca no caminho for uma dessa ta em xeque
						return true;

					}
				    else{
						j = 7;
					}
			    }
			    else{
			    	if(cor == "P"){
					if(getMatriz(i, j) == "RB" || getMatriz(i, j) == "TR"){//a primeira peca no caminho for uma dessa ta em xeque
						return true;

					}
				    else{
						j = 7;
					}

			    }
		}


				}
			}
			j--;
		}
		return 0;//se retornar zero que dizer que nao tem peca no caminho
	

	if(pos_atual_i == pos_final_i && pos_atual_j < pos_final_j)//caso 2 = andando  reto para a esquerda
	{
		int i = pos_atual_i;
		int j = pos_atual_j+1;	

		while(j < pos_final_j)
		{			
			if(tabuleiro->getMatriz(i, j) != "0")
			{				
				return 1;//caso return 1 significa que tem peca
			}
			j++;
		}

		return 0;//se retornar zero que dizer que nao tem peca no caminho		
	}

	if(pos_atual_i < pos_final_i && pos_atual_j == pos_final_j)//caso 3  = andando para baixo  reto
	{
		int i = pos_atual_i+1;
		int j = pos_atual_j;
		while(i < pos_final_i)
		{			
			if(tabuleiro->getMatriz(i, j) != "0")
			{
				return 1;//caso return 1 significa que tem peca
			}
			i++;
		}
		return 0;//se retornar zero que dizer que nao tem peca no caminho
	}

	if(pos_atual_i > pos_final_i && pos_atual_j == pos_final_j)//caso 4 = andando para cima  direita
	{
		int i = pos_atual_i-1;
		int j = pos_atual_j;
		while(i > pos_final_i)
		{			
			if(tabuleiro->getMatriz(i, j) != "0")
			{
				return 1;//caso return 1 significa que tem peca
			}
			i--;
		}
		return 0;//se retornar zero que dizer que nao tem peca no caminho
	}

	return 0;
}	


*/


