#ifndef PEAO_H
#define PEAO_H

#include <iostream>
#include <string>

class Tabuleiro;

class Peao
{
public:
	/*	INICIALIZA_POSICAO
	 *		Recebe como parametros dois inteiros que representam uma posicao i e j (respectivamente) no tabuleiro.
	 *		Armazena os parametros recebidos nos respectivos atributos destinados para eles
	 */
	void inicializa_posicao(int pos_i, int pos_j);

	/*	VERIFICA_JOGADA
	 *		Recebe como parametros dois inteiros que representam uma posicao i e j (respectivamente) no tabuleiro e, um ponteiro pro tabuleiro.
	 *		Retorna um valor logico (true ou false) informando se a jogada solicitada eh valida.
	 */
	bool verifica_jogada( int pos_final_i, int pos_final_j, Tabuleiro *tabuleiro);

	/*	GETNJOGADAS
	 *		Retorna valor inteiro referente a qtde de jogadas realizadas pela peca.
	 */
	int getNJogadas(void);

	/*	SETNJOGADAS
	 *		Incrementa valor inteiro referente a qtde de jogadas realizadas pela peca.
	 */
	void setNJogadas(void);

	/*	GETCOLUNA
	 *		Retorna valor inteiro referente a qtde de colunas deslocadas em relacao a coluna original.
	 */
	int getColuna(void);

	/*	SETCOLUNA
	 *		Incrementa/decrementa um valor inteiro de uma unidade para cada deslocamento de coluna do peao, seja direita ou esquerda.
	 */
	void setColuna(int);

	/*	POSICAO_INICIAL_I
	 *		Retorna valor inteiro referente a posicao em i ocupada pela peca.
	 */
	int posicao_inicial_i(void);

	/*	POSICAO_INICIAL_J
	 *		Retorna valor inteiro referente a posicao em j ocupada pela peca.
	 */
	int posicao_inicial_j(void);
private:
	/*	PECA_NO_CAMINHO
	 *		Retorna valor inteiro referente a presenca de peca no caminho do movimento.
	 */
	int peca_no_caminho(int pos_atual_i, int pos_atual_j, int pos_final_i, int pos_final_j, Tabuleiro *tabuleiro);
	int coluna = 0;	//Numero de colunas deslocadas de sua coluna original
	int nJogadas = 0;	//Qtde de jogadas inicializada com valor 0
	int pos_atual_i;	//posicao atual em i
	int pos_atual_j;	//posicao atual em j
};

#endif
