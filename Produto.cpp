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
	
	this->name_product = name_product;
	this->model = model;
	this->stock_quantity = stock_quantity;
	this->price = price;
	//alterar_modelo();
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

Produto Produto::set_name(){
	fflush(stdin);
	cout << "Entre com o novo nome >> ";
	getline(cin, this->name_product);
	
	Produto tmp(name_product, model,stock_quantity,price);
	return tmp;
}

Produto Produto::set_model(){
	cout << "Entre com o novo modelo >> ";
	getline(cin, this->model);
	
	Produto tmp(name_product, model,stock_quantity,price);
	return tmp;
}

Produto Produto::set_stock(){
	cout << "Entre com o novo estoque >> ";
	cin >> this->stock_quantity;
	
	Produto tmp(name_product, model,stock_quantity,price);
	return tmp;
}

Produto Produto::set_price(){
	cout << "Entre com o novo preco >> ";
	cin >> this->price;
	
	Produto tmp(name_product, model,stock_quantity,price);
	return tmp;
}

string Produto::get_name() {
	return this->name_product;
}

int Produto::get_stock(){
	return this->stock_quantity;
}

void Produto::get_product(){
	cout << "\n\n--------------------------------------------" << endl ;
	cout << "Produto: " << this->name_product << endl;;
	cout << "Modelo: " << this->model << endl;;
	cout << "Quantidade em estoque: " << this->stock_quantity << endl;
	cout << "Preco: " << this->price << endl;
	cout << "--------------------------------------------" << endl;
}

string Produto::get_model() {
	return this->model;
}

float Produto::get_price() {
	return this->price;
}

void Produto::save_product(){
	ofstream write;
	
	write.open("produtos.txt", ios::app); // abre o modo "append"
	
	write << this->name_product << endl;
	write << this->model << endl;
	write << this->stock_quantity << endl;
	write << this->price << endl;
}

int Produto::getQtdSold() {
	return qtdsold;
}

