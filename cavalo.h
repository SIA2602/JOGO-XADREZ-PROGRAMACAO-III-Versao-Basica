#ifndef PECAS_H
#define PECAS_H

#include <iostream>
#include <string>
#include <cmath>

class Tabuleiro;

class Cavalo
{
public:
	void inicializa_posicao(int pos_i, int pos_j);
	bool verifica_jogada( int pos_final_i, int pos_final_j, Tabuleiro *tabuleiro);
private:
	int pos_atual_i;
	int pos_atual_j; //posicao atual em i e j
};

#endif
