#include<iostream>
#include <fstream>
#include "Stockist.h"
#include "Produto.h"

using namespace std;

void Stockist::add_product(){
	string nome; //"nome de um produto" a ser procurado no arquivos "produtos.txt"
	int qtde; //quantidade a ser adicionada ao estoque
	int choice;
	
	cout << "01 - Criar um novo produto" << endl;
	cout << "02 - Alterar quantidade de estoque" << endl;
	cout << "Opcao: ";
	cin >> choice;
	
	fflush(stdin);
	
	if(choice == 1){
		Produto temp;
		temp.set_name();
		temp.set_model();
		temp.set_stock();
		temp.set_price();
		temp.save_product();
	}
	
	else if(choice == 2){
		cout << "Digite o nome do produto: ";
		getline(cin, nome);
		while(!this->check_product(nome)){
			cout << "Produto inexistente, entre com um nome valido: ";
			getline(cin, nome);
		}
		
			cout << "Digite a quantidade a ser adicionada: ";
			cin >> qtde;
		
			this->change_stock(nome, qtde);
	}
	else
		cout << "Entrada invalida" << endl;
}

bool Stockist::check_product(string nome){
	ifstream file;
	string input;
	bool flag = false;
	
	file.open("produtos.txt");
	
	while(!file.eof()){
		getline(file, input);
		if(input == nome){
			flag = true;
			break;	
		}
	}
	return flag;
}

void Stockist::change_stock(string nome, int qtde){
	string input, modelo;
	int qtde_anterior;
	float preco;
	
	ifstream read("produtos.txt"), read1;
	ofstream write("temp.txt"), write1;

	
	while (!read.eof()){
		getline(read, input);
		if(input == nome){
			getline(read, input);	
			modelo = input; //o proximo parametro depois do nome e o modelo
			getline(read, input); 
			stringstream intValue(input); //aqui se tem a quantidade e e feita a conversao para inteiro
			intValue >> qtde_anterior;
			getline(read,input);
			stringstream floatValue(input); //aqui se tem a preco e e feita a conversao para inteiro
			floatValue >> preco;
		}
	}
	
	read.close();
	
	Produto temp(nome, modelo, qtde_anterior, preco);
	
	temp = temp + qtde; //sobrecarga de operador
	
	read.open("produtos.txt");
	
	while(!read.eof()){
		getline(read, input);
		if(input == nome){
			write << input << endl;
			getline(read, input); 
			write << input << endl;
			getline(read, input); 
			write <<  temp.get_stock() << endl;
		}
		else
			write << input << endl;
	}
	
	read.close();
	write.close();

	read1.open("temp.txt");
	write1.open("produtos.txt");
	
	while (!read1.eof()){
		getline(read1, input);
    	write1 << input <<endl;
	}
}

