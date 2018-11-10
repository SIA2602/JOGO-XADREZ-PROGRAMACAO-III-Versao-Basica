#include "tabuleiro.h"
#include <iostream>



bool Tabuleiro :: roque(int pos_final_i, int pos_final_j, char ){
	if(_rei_branco.getNjogadas() == 0 && pos_final_i == 7 && pos_final_j == 6 && getMatriz(7, 5) == "0" && getMatriz(7, 6) == "0" && _rei_branco.getNjogadas() == 0 ){//roque menor pecas branca
		std::cout<< "ROQUE MENOR BRANCAS";
		setMatriz(pos_final_i, pos_final_j, getMatriz(_rei_branco.posicao_inicial_i(), _rei_branco.posicao_inicial_j()));
		setMatriz(_rei_branco.posicao_inicial_i(), _rei_branco.posicao_inicial_j(), "0");
		_rei_branco.inicializa_posicao(pos_final_i, pos_final_j);
		_rei_branco.getNjogadas() ;
		//movimento torre
		setMatriz(7, 5, getMatriz(7, 7));
		setMatriz(7, 7, "0");
		_torres_brancas[1].inicializa_posicao(7, 5);
		_torres_brancas[1].setNjogadas();
		return true;
	}
	
	if(_rei_branco.getNjogadas() == 0 && pos_final_i == 7 && pos_final_j == 2 && getMatriz(7, 1) == "0" && getMatriz(7,2) == "0" && getMatriz(7, 3) == "0" && _torres_brancas[1].getNjogadas() == 0) {//roque maior branco
		setMatriz(pos_final_i, pos_final_j,getMatriz(_rei_branco.posicao_inicial_i(), _rei_branco.posicao_inicial_j()));
		setMatriz(_rei_branco.posicao_inicial_i(), _rei_branco.posicao_inicial_j(), "0");
		_rei_branco.inicializa_posicao(7, 2);
		_rei_branco.getNjogadas() ;
		//movimento torre
		setMatriz(7, 3,getMatriz(7, 0));
		setMatriz(7, 0, "0");
		_torres_brancas[0].inicializa_posicao(7, 3);
		_torres_brancas[0].setNjogadas();
		return true;
	}


	if(_rei_preto.getNjogadas() == 0 && pos_final_i == 0 && pos_final_j == 6 && getMatriz(0, 5) == "0" && getMatriz(0, 6) == "0" && _torres_pretas[0].getNjogadas() == 0) {//roque menor pecas branca
		//std::cout<< "ROQUE MENOR pretas";
		setMatriz(pos_final_i, pos_final_j, getMatriz(_rei_preto.posicao_inicial_i(), _rei_preto.posicao_inicial_j()));
		setMatriz(_rei_preto.posicao_inicial_i(), _rei_preto.posicao_inicial_j(), "0");
		_rei_preto.inicializa_posicao(pos_final_i, pos_final_j);
		_rei_preto.setNjogadas();
		//TORRE
		setMatriz(0, 5, getMatriz(0, 7));
		setMatriz(0, 7, "0");
		_torres_pretas[1].inicializa_posicao(0, 5);
		_torres_pretas[1].setNjogadas();
		return true;
	}


	if(_rei_preto.getNjogadas() == 0 && pos_final_i == 0 && pos_final_j == 2 && getMatriz(0, 1) == "0" && getMatriz(0,2) == "0" && getMatriz(0, 3) == "0" && _torres_pretas[1].getNjogadas() == 0) {//roque maior pecas bramcas		
		//std::cout<< "ROQUE MaiOR PRETAS";
		setMatriz(pos_final_i, pos_final_j, getMatriz(_rei_preto.posicao_inicial_i(), _rei_preto.posicao_inicial_j()));
		setMatriz(_rei_preto.posicao_inicial_i(), _rei_preto.posicao_inicial_j(), "0");
		_rei_preto.inicializa_posicao(pos_final_i, pos_final_j);
		_torres_pretas[1].getNjogadas() ;
		setMatriz(0, 3, getMatriz(0, 0));
		setMatriz(0, 0, "0");
		_torres_pretas[0].inicializa_posicao(0, 3);
		_torres_pretas[0].setNjogadas();
		return true;

	}
	return false;


}

bool Tabuleiro:: xeque_RP( int n , int m){//da pra verificar na (0,2)(0,4)(0,6) os risco para o rei
	int i = n;
	int j = m;
	while( j > 0 ){
	//percorrendo para direita reto e analisando se tem alguna peca a adversaria""
				std::cout<<"DANIELA";		
		if(getMatriz(i, j) != "0"){
			if(((i == 1 ) && (j == 3)) || ((i == 1) && (j == 1)) || ((i == 1) && (j == 5))){

				if((getMatriz(i, j) == "P1B") ||(getMatriz(i, j) == "P2B")||(getMatriz(i, j) == "P3B") ||
				 (getMatriz(i, j) == "P4B" )||(getMatriz(i, j) == "P5B") ||(getMatriz(i, j) == "P6B" ) ||
				 (getMatriz(i, j) == "P7B" )|| (getMatriz(i, j) == "P8B")){
					return true;
				}
			}
			if(getMatriz(i, j) == "B1B" || getMatriz(i, j) == "B2B"|| getMatriz(i,j) == "RB" ){//a primeira peca no caminho for uma dessa ta em xeque
					return true;
			}
			else{j = 0;}
		}	
		i++;
		j--;
	}
	i = n;
	i = m;
	/*
	while( j < 7){
		if(getMatriz(i, j) != "0"){
			if((i == 1 && j == 3) ||(i == 1 && j == 5) || (i == 1 && j ==7)){
				if((getMatriz(i, j) == "P1B") ||(getMatriz(i, j) == "P2B")||(getMatriz(i, j) == "P3B") ||
				 (getMatriz(i, j) == "P4B" )||(getMatriz(i, j) == "P5B") ||(getMatriz(i, j) == "P6B" ) ||
				 (getMatriz(i, j) == "P7B" )|| (getMatriz(i, j) == "P8B")){return true;}
			}
			if(getMatriz(i, j) == "B1B" || getMatriz(i, j) == "B2B"|| getMatriz(i,j) == "RB" ){//a primeira peca no caminho for uma dessa ta em xeque
					return true;
			}
			else{j = 3;}
			}	
		i++;
		j++;
	}
	i = n;
	i = m;
	*/
	while(  j < 7){
		std::cout<<"DANIELA";
		if(getMatriz(i, j) != "0"){	
			if(getMatriz(i, j) == "T1B" || getMatriz(i, j) == "T2B"|| getMatriz(i,j) == "RB" ){//a primeira peca no caminho for uma dessa ta em xeque
					return true;
			}
			else{j = 3;}
		}	
		i++;
		
	}
	return false;
}





