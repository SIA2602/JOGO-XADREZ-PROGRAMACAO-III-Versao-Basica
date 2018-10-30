#include <iostream>
#include <string>

#include "tabuleiro.h"

using namespace std;

class Bispo
{

public:
	void inicializa_posicao(int pos_i, int pos_j);

private:

	int pos_atual_i, pos_atual_j; //posicao atual em i e j	
	bool verifica_jogada(int pos_final_i, int pos_final_j, Tabuleiro *tabuleiro);
};


void inicializa_posicao(int pos_i, int pos_j)
{
	pos_atual_i = pos_i;
	pos_atual_j = pos_j;
	return;
}

bool verifica_jogada( int pos_final_i, int pos_final_j, Tabuleiro *tabuleiro)
{
	//verificando se caminho final eh valido
	if( (pos_final_j - pos_final_i) == (pos_atual_j - pos_atual_i) ||  (pos_final_j + pos_final_i) == (pos_atual_j + pos_atual_i) ) // caso nao seja invalida a posicao
	{

	}

	else return false;
}