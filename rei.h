#ifndef REI_H
#define REI_H

#include <iostream>
#include <string>

class Tabuleiro;

class Rei
{
public:

	void inicializa_posicao(int pos_i, int pos_j);	

	bool verifica_jogada( int pos_final_i, int pos_final_j, Tabuleiro *tabuleiro);	

private:

	int peca_no_caminho_torre(int pos_atual_i, int pos_atual_j, int pos_final_i, int pos_final_j, Tabuleiro *tabuleiro);

  	int peca_no_caminho_bispo(int pos_atual_i, int pos_atual_j, int pos_final_i, int pos_final_j, Tabuleiro *tabuleiro);  	

	int pos_atual_i;
	int pos_atual_j; //posicao atual em i e j
};

#endif