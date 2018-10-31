#ifndef BISPO_H
#define BISPO_H

#include <iostream>
#include <string>

class Bispo
{

public:

	void inicializa_posicao(int pos_i, int pos_j);	

	//funcao responsavel por verificar se a jogada eh valida
	bool verifica_jogada( int pos_final_i, int pos_final_j, Tabuleiro *tabuleiro);	

	int peca_no_caminho(pos_atual_i,pos_atual_j, pos_final_i, pos_final_j, Tabuleiro *tabuleiro);	

private:
	int pos_atual_i;
	int pos_atual_j; //posicao atual em i e j
};

#endif
