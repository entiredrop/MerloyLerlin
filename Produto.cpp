#include "Produto.h"
#include <stdio.h>
#include <stdlib.h>
# include <iostream>

using namespace std;

Produto::Produto(){
	strcpy(this->nome_produto, "None");
	strcpy(this->modelo, "None");
	this->quantidade_estoque = 0;
	this->preco = 0;
}

Produto::Produto(char nome_produto[], char modelo[], int quantidade_estoque, float preco){
	
	strcpy(this->nome_produto, nome_produto);
	strcpy(this->modelo, modelo);
	this->quantidade_estoque = quantidade_estoque;
	this->preco = preco;alterar_modelo()`
}

Produto Produto::operator +(int unidades){
	this->quantidade_estoque = this->quantidade_estoque + unidades;
}


Produto Produto::operator -(int unidades){
	this->quantidade_estoque = this->quantidade_estoque - unidades;
}

void Produto::alterar_nome(){
	cout << "Entre com o novo nome >> ";
	cin >> this->nome_produto;
}

void Produto::alterar_modelo(){
	cout << "Entre com o novo modelo >> ";
	cin >> this->modelo;
}

void Produto::alterar_estoque(){
	cout << "Entre com o novo estoque >> ";
	cin >> this->quantidade_estoque;
}

void Produto::alterar_preco(){
	cout << "Entre com o novo preco >> ";
}

void Produto::consultar_produto(){
	cout << "Produto: " << this->nome_produto << endl;;
	cout << "Modelo: " << this->modelo << endl;;
	cout << "Quantidade em estoque" << this->quantidade_estoque << endl;
	cout << "Preco" << this->preco << endl;
}
