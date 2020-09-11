#include "Produto.h"
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>
#include <fstream> // ofstream e ifstream
#include <string>

using namespace std;

Produto::Produto(){
	this->name_product = "None";
	this->model = "None";
	this->stock_quantity = 0;
	this->price = 0;
}

Produto::Produto(string name_product, string model, int stock_quantity, float price){
	
	strcpy(this->nome_produto, nome_produto);
	strcpy(this->modelo, modelo);
	this->quantidade_estoque = quantidade_estoque;
	this->preco = preco;
	alterar_modelo();
}



// Comprar de produto, incrementar estoque
Produto Produto::operator +(int units){
	Produto aux = *this;
	aux.stock_quantity = (this->stock_quantity + units);
	return aux;
}

// Venda de produtos, decrementar estoque
Produto Produto::operator -(int units){
	Produto aux = *this;
	aux.stock_quantity = (this->stock_quantity - units);
	return aux;
}

void Produto::set_name(){
	cout << "Entre com o novo nome >> ";
	getline(cin, this->name_product);
}

void Produto::set_model(){
	cout << "Entre com o novo modelo >> ";
	getline(cin, this->model);
}

void Produto::set_stock(){
	cout << "Entre com o novo estoque >> ";
	cin >> this->stock_quantity;
}

void Produto::set_price(){
	cout << "Entre com o novo preco >> ";
	cin >> this->price;
}

void Produto::get_produt(){
	cout << "\n\n--------------------------------------------" << endl ;
	cout << "Produto: " << this->name_product << endl;;
	cout << "Modelo: " << this->model << endl;;
	cout << "Quantidade em estoque: " << this->stock_quantity << endl;
	cout << "Preco: " << this->price << endl;
	cout << "--------------------------------------------\n\n" << endl;
}

void Produto::save_product(){
	ofstream write;
	
	write.open("produtos.txt", ios::app); // abre o modo "append"
	
	write << this->name_product << endl;
	write << this->model << endl;
	write << this->stock_quantity << endl;
	write << this->price << endl;
}

