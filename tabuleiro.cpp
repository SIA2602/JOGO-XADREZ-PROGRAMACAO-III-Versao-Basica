#include "tabuleiro.h"
#include <iostream>
#include <string>
#include <vector>


//incializando pecas no tabuleiro
Tabuleiro::Tabuleiro()
{
	for(int i = 0; i < 8; i++) {

		for(int j = 0; j < 8; j++) {

			_matriz[i][j] = "0";
		}
	}
	//colocando pecas brancas em suas posicoes
	_cavalos_brancos[0].inicializa_posicao(7,1);
	_cavalos_brancos[1].inicializa_posicao(7,6);
	_rei_branco.inicializa_posicao(7,4);
	_rainha_branca.inicializa_posicao(7,3);
	_bispos_brancos[0].inicializa_posicao(7,2);
	_bispos_brancos[1].inicializa_posicao(7,5);
	_torres_brancas[0].inicializa_posicao(7,0);
	_torres_brancas[1].inicializa_posicao(7,7);
	for(int i=0; i<8; i++)
	{
		_peoes_brancos[i].inicializa_posicao(6,i);
	}

	//colocando pecas pretas em suas posicoes
	_cavalos_pretos[0].inicializa_posicao(0,1);
	_cavalos_pretos[1].inicializa_posicao(0,6);
	_rei_preto.inicializa_posicao(0,4);
	_rainha_preta.inicializa_posicao(0,3);
	_bispos_pretos[0].inicializa_posicao(0,2);
	_bispos_pretos[1].inicializa_posicao(0,5);
	_torres_pretas[0].inicializa_posicao(0,0);
	_torres_pretas[1].inicializa_posicao(0,7);
	for(int i=0; i<8; i++)
	{
		_peoes_pretos[i].inicializa_posicao(1,i);
	}
	//colocando pecas no tabuleiro
	_matriz[0][0] = "T1P";
	_matriz[0][7] = "T2P"; // T = torre e B = branca
	_matriz[0][1] = "C1P";
	_matriz[0][6] = "C2P";
	_matriz[0][2] = "B1P";
	_matriz[0][5] = "B2P";
	_matriz[0][3] = "RP";
	_matriz[0][4] = "DP";
	for(int i=0; i<8; i++)
	{
		_matriz[1][i] = std::string("P") + char('1' + i) + "P";
	}

	_matriz[7][0] = "T1B";
	_matriz[7][7] = "T2B"; // T = torre e B = branca
	_matriz[7][1] = "C1B";
	_matriz[7][6] = "C2B";
	_matriz[7][2] = "B1B";
	_matriz[7][5] = "B2B";
	_matriz[7][3] = "RB";
	_matriz[7][4] = "DB";
	for(int i=0; i<8; i++)
	{
		_matriz[6][i] = std::string("P") + char('1' + i) + "B";
	}
}


bool Tabuleiro::jogada(const std::string& nome_peca, int pos_i_final, int pos_j_final, std::string jogada)
{
	if(pos_i_final > 7 || pos_j_final > 7 || pos_i_final < 0 || pos_j_final < 0) return false;
	//if (roque(pos_i_final, pos_j_final,nome_peca[0])== true) return true;
	//xeque_RP(0 , 4);		
	if(nome_peca == "0") return false;

	historico_jogadas.push_back(jogada); //armazenando a jogada realizada

	char tipo = nome_peca[0];
	char cor = nome_peca[nome_peca.size() - 1];
	int numero = nome_peca[1] - '1';

	if( cor == 'P')
	{
		switch(tipo)
		{

			case 'T':
				return _torres_pretas[numero].verifica_jogada(pos_i_final, pos_j_final, this);
			case 'C':
				return _cavalos_pretos[numero].verifica_jogada(pos_i_final, pos_j_final, this);
			case 'B':
				return _bispos_pretos[numero].verifica_jogada(pos_i_final, pos_j_final, this);
			case 'P':
				return _peoes_pretos[numero].verifica_jogada(pos_i_final, pos_j_final, this);
			case 'R':
				return _rei_preto.verifica_jogada(pos_i_final, pos_j_final, this);
			case 'D':
				return _rainha_preta.verifica_jogada(pos_i_final, pos_j_final, this);
		}
	}

	else if( cor == 'B')
	{
		switch(tipo)
		{

			case 'T':
				return _torres_brancas[numero].verifica_jogada(pos_i_final, pos_j_final, this);
			case 'C':
				return _cavalos_brancos[numero].verifica_jogada(pos_i_final, pos_j_final, this);
			case 'B':
				return _bispos_brancos[numero].verifica_jogada(pos_i_final, pos_j_final, this);
			case 'P':
				return _peoes_brancos[numero].verifica_jogada(pos_i_final, pos_j_final, this);
			case 'R':
				return _rei_branco.verifica_jogada(pos_i_final, pos_j_final, this);
			case 'D':
				return _rainha_branca.verifica_jogada(pos_i_final, pos_j_final, this);
		}
	}

	return false;
}


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





