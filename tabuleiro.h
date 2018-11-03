#ifndef TABULEIRO_H
#define TABULEIRO_H

#include <string>

#include "cavalo.h"
#include "rei.h"
#include "rainha.h"
#include "bispo.h"
#include "peao.h"
#include "torre.h"

class Tabuleiro {

public:

	//incializando pecas no tabuleiro
	Tabuleiro()
	{

		for(int i = 0; i < 8; i++) {

			for(int j = 0; j < 8; j++) {

				_matriz[i][j] = "0";
			}
		}
		//colocando pecas brancas em suas posicoes
		_cavalos_brancos[0].inicializa_posicao(0,1);
		_cavalos_brancos[1].inicializa_posicao(0,6);
		_rei_branco.inicializa_posicao(0,3);
		_rainha_branca.inicializa_posicao(0,4);
		_bispos_brancos[0].inicializa_posicao(0,2);
		_bispos_brancos[1].inicializa_posicao(0,5);
		_torres_brancas[0].inicializa_posicao(0,0);
		_torres_brancas[1].inicializa_posicao(0,7);
		for(int i=0; i<8; i++)
		{
			_peoes_brancos[i].inicializa_posicao(1,i);
		}

		//colocando pecas pretas em suas posicoes
		//_cavalos_pretos[0].inicializa_posicao(7,1);
		//_cavalos_pretos[1].inicializa_posicao(7,6);
		_rei_preto.inicializa_posicao(7,3);
		_rainha_preta.inicializa_posicao(7,4);
		_bispos_pretos[0].inicializa_posicao(7,2);
		_bispos_pretos[1].inicializa_posicao(7,5);
		_torres_pretas[0].inicializa_posicao(7,0);
		_torres_pretas[1].inicializa_posicao(7,7);
		for(int i=0; i<8; i++)
		{
			_peoes_pretos[i].inicializa_posicao(6,i);
		}


		//colocando pecas no tabuleiro
		_matriz[0][0] = "T1B";
		_matriz[0][7] = "T2B"; // T = torre e B = branca
		_matriz[0][1] = "C1B";
		_matriz[0][6] = "C2B";
		_matriz[0][2] = "B1B";
		_matriz[0][5] = "B2B";
		_matriz[0][3] = "RB";
		_matriz[0][4] = "DB";
		for(int i=0; i<8; i++)
		{
			_matriz[1][i] = std::string("P") + char('1' + i) + "B";
		}

		_matriz[7][0] = "T1P";
		_matriz[7][7] = "T2P"; // T = torre e B = branca
		_matriz[7][1] = "C1P";
		_matriz[7][6] = "C2P";
		_matriz[7][2] = "B1P";
		_matriz[7][5] = "B2P";
		_matriz[7][3] = "RP";
		_matriz[7][4] = "DP";
		for(int i=0; i<8; i++)
		{
			_matriz[6][i] = std::string("P") + char('1' + i) + "P";
		}
	}

	std::string getMatriz(int lin, int col)
	{
		return _matriz[lin][col];

	}
	void setMatriz(int lin, int col, const std::string& pec){
		_matriz[lin][col] = pec;
	}

	bool jogada(const std::string& nome_peca, int pos_i_final, int pos_j_final)
	{
		if(pos_i_final > 7 || pos_j_final > 7 || pos_i_final < 0 || pos_j_final < 0) return false;

		if(nome_peca == "0") return false;

		char tipo = nome_peca[0];
		char cor = nome_peca[nome_peca.size() - 1];
		int numero = nome_peca[1] - '1';

		if( cor == 'P')
		{
			switch(tipo)
			{

				case 'T':
					return _torres_pretas[numero].verifica_jogada(pos_i_final, pos_j_final, this);
				/*case 'C':
					return _cavalos_pretos[numero].verifica_jogada(pos_i_final, pos_j_final, this);*/
				case 'B':
					return _bispos_pretos[numero].verifica_jogada(pos_i_final, pos_j_final, this);
				/*case 'P':
					return _peoes_pretos[numero].verifica_jogada(pos_i_final, pos_j_final, this);	*/
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
				/*case 'C':
					return _cavalos_brancos[numero].verifica_jogada(pos_i_final, pos_j_final, this);*/
				case 'B':
					return _bispos_brancos[numero].verifica_jogada(pos_i_final, pos_j_final, this);
				/*case 'P':
					return _peoes_brancos[numero].verifica_jogada(pos_i_final, pos_j_final, this);	*/
				case 'R':
					return _rei_branco.verifica_jogada(pos_i_final, pos_j_final, this);
				case 'D':
					return _rainha_branca.verifica_jogada(pos_i_final, pos_j_final, this);
			}
		}

		return false;
	}
	//adicionar funcoes conforme necessidade

private:
	//matriz = tabuleiro
	std::string _matriz[8][8]; // "_" significa privado

	//pecas do time branco
	Cavalo _cavalos_brancos[2];
	Rei _rei_branco;
	Rainha _rainha_branca;
	Bispo _bispos_brancos[2];
	Peao _peoes_brancos[8];
	Torre _torres_brancas[2];

	//pecas do time preto
	Cavalo _cavalos_pretos[2];
	Rei _rei_preto;
	Rainha _rainha_preta;
	Bispo _bispos_pretos[2];
	Peao _peoes_pretos[8];
	Torre _torres_pretas[2];

};

#endif // TABULEIRO_H
