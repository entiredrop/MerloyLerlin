/*#include<iostream>
#include<fstream>
#include "Salesman.h"
#include<sstream>

using namespace std;

Stock *s = s->getInstance();

void Salesman::remove_product(){
	ifstream file;
	file.open("produtos.txt");
	string input;
	
	string nome; //"nome de um produto" a ser procurado no arquivos "products.txt"
	int qtde; //quantidade vendida
	
	fflush(stdin);
	
	cout << "Digite o nome do produto: ";
	getline(cin, nome);
	
	//Stockist temp;
		
	while(!s->check_product(nome)){
		cout << "Produto inexistente no estoque. Digite um produto valido: ";
		getline(cin, nome);
	}
	
	cout << "Digite a quantidade vendida: ";
	cin >> qtde;
	
	s->remove_stock(nome,qtde);
	//this->sell_product(nome, qtde);
	
	file.close();
}

void Salesman::sell_product(string nome, int qtde){
	//Gravar em um arquivo a venda, produto   valor    valor total
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
	
	temp = temp - qtde; //sobrecarga de operador
	
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

*/
