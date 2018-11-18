#include "tabuleiro.h"
#include <ctype.h>
#include <iostream>
#include <string>
#include <vector>
#include <cmath>

//incializando pecas no tabuleiro
Tabuleiro::Tabuleiro()
{
	for(int i = 0; i < 8; i++)
	{

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

	if (roque(pos_i_final, pos_j_final,nome_peca[0])== true)
	{
		std::cout<<"Jogada por Roque \n";
		return true;
	}

	if(nome_peca == "0") return false;

	if( historico_jogadas.size() != 0 )
	{
		if( en_passant(nome_peca, pos_i_final, pos_j_final) == true )
		{
			std::cout << "Jogada por en-passant" << std::endl;
			return true;
		}
	}

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
			default:
				return false;
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
			default:
				return false;
		}
	}

	return false;
}

bool Tabuleiro::en_passant( std::string nome_peca, int linha_final, int coluna_final )
{
	//nome_peca esta no padrao P1P ou P1B sendo o 1 um numero qualquer de 1 a 8
	//linha_final eh a linha final ao qual o peao ira se deslocar
	//coluna_final eh a coluna final ao qual o peao ira se deslocar
	std::string nome_peca_anterior;
	int linha_peca_anterior, coluna_peca_anterior;

	std::string jogada_anterior = historico_jogadas[historico_jogadas.size()-1];//pega a ultima jogada
	decofica_jogada_anterior( nome_peca[2],nome_peca_anterior, linha_peca_anterior, coluna_peca_anterior, jogada_anterior );

	//pegando posicao de cada peao
	int numero = nome_peca[1] - '1';
	int numero_anterior = nome_peca_anterior[1] - '1';

	if( historico_jogadas.size() != 0 ) //evitar erro de segmentacao
	{
		if( nome_peca_anterior[0] == 'P' && nome_peca[0] == 'P' ) //verificando se sao dois peoes
		{
			//caso branco tenha que comer o peao preto
			if( nome_peca_anterior[2] == 'P'&& _peoes_pretos[coluna_peca_anterior].get_duas_vezes() == true) //caso o peao que sera comido andou duas casas
			{
				if(_peoes_pretos[coluna_peca_anterior].get_linha_atual() == 3 && linha_final+1 == 3) //caso estejam na linha 5 do xadrez
				{
					if( abs(linha_final- _peoes_brancos[numero].get_linha_atual()) == 2 ) _peoes_brancos[numero].set_duas_vezes_true();
							else _peoes_brancos[numero].set_duas_vezes_false();

					setMatriz(linha_final, coluna_final, getMatriz(_peoes_brancos[numero].get_linha_atual(), _peoes_brancos[numero].get_coluna_atual()));
								setMatriz(_peoes_brancos[numero].get_linha_atual(), _peoes_brancos[numero].get_coluna_atual(), "0");
								setMatriz(_peoes_pretos[numero_anterior].get_linha_atual(), _peoes_pretos[numero_anterior].get_coluna_atual(), "0");
								_peoes_brancos[numero].inicializa_posicao(linha_final, coluna_final);
								_peoes_brancos[numero].incremento_nJogadas();
					return true;
				}

				else return false;
			}

			//caso preta tenha que comer o peao branco
			else if( nome_peca_anterior[2] == 'B'&& _peoes_brancos[coluna_peca_anterior].get_duas_vezes() == true) //caso o peao que sera comido andou duas casas
			{
				if(_peoes_brancos[coluna_peca_anterior].get_linha_atual() == 4 && linha_final-1 == 4) //caso estejam na linha 5 do xadrez
				{
					if( abs(linha_final- _peoes_pretos[numero].get_linha_atual()) == 2 ) _peoes_pretos[numero].set_duas_vezes_true();
							else _peoes_pretos[numero].set_duas_vezes_false();

					setMatriz(linha_final, coluna_final, getMatriz(_peoes_pretos[numero].get_linha_atual(), _peoes_pretos[numero].get_coluna_atual()));
								setMatriz(_peoes_pretos[numero].get_linha_atual(), _peoes_pretos[numero].get_coluna_atual(), "0");
								setMatriz(_peoes_brancos[numero_anterior].get_linha_atual(), _peoes_brancos[numero_anterior].get_coluna_atual(), "0");
								_peoes_pretos[numero].inicializa_posicao(linha_final, coluna_final);
								_peoes_pretos[numero].incremento_nJogadas();
					return true;
				}

				else return false;
			}

			else return false;
		}

		else return false;
	}

	else return false;
}

// ROQUE MAIOR E ROQUE MENOR
bool Tabuleiro :: roque(int pos_final_i, int pos_final_j, char ){
	if(_rei_branco.getNjogadas() == 0 && pos_final_i == 7 && pos_final_j == 6 && getMatriz(7, 5) == "0" && getMatriz(7, 6) == "0" && _rei_branco.getNjogadas() == 0 ){//roque menor pecas branca
		if((xeque( 7, 4))==true|| (xeque( 7, 6))== true)return false;
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
		if((xeque( 7, 4))==true|| (xeque( 7, 2))== true)return false;
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
		if((xeque(0,4))==true|| (xeque(0,6))== true)return false;
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
		if((xeque(0,4))==true|| (xeque(0,2))== true)return false;
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

//XEQUE
bool Tabuleiro:: xeque( int n , int m){//da pra verificar na (0,2)(0,4)(0,6) os risco para o rei
	int i = n;
	int j = m;

	if (m == 0 && n == 6){
		for (j = 0; j < 8; j++){
			if ((getMatriz(1, j) == "C1P") || (getMatriz(1, j) == "C2P")){
				if( (j == 2)|| (j == 4) ||(j == 6)){
					return true;
				}
			}
			if ((getMatriz(2, j) == "C1P") || (getMatriz(2, j) == "C2P")){
				if( (j == 3)|| (j == 5) ||(j == 7)){
					return true;
				}
			}
		}
	}
	if (m == 0 && n == 2){
		for (j = 0; j < 8; j++){
			if ((getMatriz(1, j) == "C1P") || (getMatriz(1, j) == "C2P")){
				if( (j == 4)|| (j == 2) ||(j == 0)||(j == 6)){
					return true;
				}
			}
			if ((getMatriz(2, j) == "C1P") || (getMatriz(2, j) == "C2P")){
				if( (j == 5)|| (j == 3) ||(j == 1)){
					return true;
				}
			}
		}
	}
	return false;
}
