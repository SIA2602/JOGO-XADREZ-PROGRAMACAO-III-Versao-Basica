#ifndef PEAO_H
#define PEAO_H

#include <iostream>
#include <string>

class Tabuleiro;

class Peao
{
public:
	void inicializa_posicao(int pos_i, int pos_j);
	bool verifica_jogada( int pos_final_i, int pos_final_j, Tabuleiro *tabuleiro);
	int get_nJogadas(void);
private:
	int peca_no_caminho(int pos_atual_i, int pos_atual_j, int pos_final_i, int pos_final_j, Tabuleiro *tabuleiro);
	int nJogadas = 0;
	int pos_atual_i;
	int pos_atual_j; //posicao atual em i e j
};

#endif
