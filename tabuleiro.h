#ifndef TABULEIRO_H
#define TABULEIRO_H

#include <string>
#include <vector>

#include "cavalo.h"
#include "rei.h"
#include "rainha.h"
#include "bispo.h"
#include "peao.h"
#include "torre.h"

class Tabuleiro {

public:

	//incializando pecas no tabuleiro
	Tabuleiro();

	std::string getMatriz(int lin, int col) {return _matriz[lin][col];}

	void setMatriz(int lin, int col, const std::string& pec) {_matriz[lin][col] = pec;}

	int switch_para_letra(char letra)
	{
		switch(letra)
		{
			case 'a':
				return 0;
			case 'b':
				return 1;
			case 'c':
				return 2;
			case 'd':
				return 3;
			case 'e':
				return 4;
			case 'f':
				return 5;
			case 'g':
				return 6;
			case 'h':
				return 7;
			default:
				return -1;
		}

		return -1;
	}

	int switch_para_numero(char numero)
	{
		switch(numero)
		{
			case '1':
				return 7;
			case '2':
				return 6;
			case '3':
				return 5;
			case '4':
				return 4;
			case '5':
				return 3;
			case '6':
				return 2;
			case '7':
				return 1;
			case '8':
				return 0;
			default:
				return -1;
		}

		return -1;
	}

	std::string switch_char_string(char letra)
	{
		switch(letra)
		{
			case 'C':
				return std::string("C");
			case 'T':
				return std::string("T");
			case 'B':
				return std::string("B");
			case 'D':
				return std::string("D");
			case 'R':
				return std::string("R");
			default:
				return std::string("erro");
		}

		return std::string("erro");
	}


	void decofica_jogada_anterior( char cor_peca_atual, std::string &nome_peca_anterior, int &linha_peca_anterior, int &coluna_peca_anterior, std::string jogada_anterior )
	{
		char cor_peca_anterior;

		if(cor_peca_atual == 'P') cor_peca_anterior = 'B';
		else cor_peca_anterior = 'P';

		linha_peca_anterior = switch_para_numero(char(jogada_anterior[1]));
		coluna_peca_anterior = switch_para_letra(char(jogada_anterior[0]));
		nome_peca_anterior = std::string("P") + char('1' + switch_para_letra(jogada_anterior[0])) + cor_peca_anterior;
		return;
	}

	bool en_passant( std::string nome_peca, int linha_final, int coluna_final );

	bool roque(int, int, char);

	bool xeque( int n , int m);

	bool jogada(const std::string& nome_peca, int pos_i_final, int pos_j_final, std::string jogada);

	std::vector<std::string> getHistoricoJogadas() { return historico_jogadas; }

	//adicionar funcoes conforme necessidade

private:
	//matriz = tabuleiro
	std::string _matriz[8][8]; // "_" significa privado

	std::vector<std::string> historico_jogadas; //armazena o historico de jogadas

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
