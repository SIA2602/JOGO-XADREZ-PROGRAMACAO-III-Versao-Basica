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
		//colocando pecas brancas em suas posicoes
		_cavalos_brancos[0].inicializa_posicao(0,1);
		_cavalos_brancos[1].inicializa_posicao(0,6);
		_rei_branco.inicializa_posicao(0,3);
		_rainha_branca.inicializa_posicao(0,4);
		_bispos_brancos[0].inicializa_posicao(0,2);
		_bispos_brancos[1].inicializa_posicao(0,5);
		_torres_bracas[0].inicializa_posicao(0,0);
		_torres_bracas[1].inicializa_posicao(0,7);
		for(int i=0; i<8; i++)
		{
			_peoes_brancos[i].inicializa_posicao(1,i);
		}

		//colocando pecas pretas em suas posicoes
		_cavalos_pretos[0].inicializa_posicao(7,1);
		_cavalos_pretos[1].inicializa_posicao(7,6);
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
		_matriz[0][0] = _matriz[0][7] = "TB"; // T = torre e B = branca
		_matriz[0][1] = _matriz[0][6] = "CB";
		_matriz[0][2] = _matriz[0][5] = "BB";
		_matriz[0][3] = "RB";
		_matriz[0][4] = "DB";
		for(int i=0; i<8; i++)
		{
			_matriz[1][i] = "PB";
		}

		_matriz[7][0] = _matriz[0][7] = "TB"; // T = torre e B = branca
		_matriz[7][1] = _matriz[0][6] = "CB";
		_matriz[7][2] = _matriz[0][5] = "BB";
		_matriz[7][3] = "RB";
		_matriz[7][4] = "DB";
		for(int i=0; i<8; i++)
		{
			_matriz[6][i] = "PB";
		}

	}
	std::string getMatriz(int lin, int col){
			return matriz[lin][col];
		
	}
	void setMatriz(int lin, int col, char pec){
		matriz[lin][col] = pec;
	}
	//adicionar funcoes conforme necessidade

private:
	//matriz = tabuleiro
	string _matriz[8][8]; // "_" significa privado "padrao do samuel"

	//pecas do time branco
	Cavalo _cavalos_brancos[2];
	Rei _rei_branco;
	Rainha _rainha_branca;
	Bispo _bispos_brancos[2];
	Peao _peoes_brancos[8];
	Torre _torres_bracas[2];

	//pecas do time preto
	Cavalo _cavalos_pretos[2];
	Rei _rei_preto;
	Rainha _rainha_preta;
	Bispo _bispos_pretos[2];
	Peao _peoes_pretos[8];
	Torre _torres_pretas[2];

};

#endif // TABULEIRO_H
