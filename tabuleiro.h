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
	
	bool roque(int, int, char);	

	bool xeque_RP(int n, int m);

	bool jogada(const std::string& nome_peca, int pos_i_final, int pos_j_final, std::string jogada);

	bool xeque_RB( int n , int m);

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