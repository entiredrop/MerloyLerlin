#include<iostream>
#include<fstream>
#include "Salesman.h"
#include "Stockist.h"
#include<sstream>

using namespace std;

void Salesman::remove_product(){
	ifstream file;
	file.open("produtos.txt");
	string input;
	
	string nome; //"nome de um produto" a ser procurado no arquivos "products.txt"
	int qtde; //quantidade vendida
	
	fflush(stdin);
	
	cout << "Digite o nome do produto: ";
	getline(cin, nome);
	
	Stockist temp;
		
	while(!temp.check_product(nome)){
		cout << "Produto inexistente no estoque. Digite um produto valido: ";
		getline(cin, nome);
	}
	
	cout << "Digite a quantidade vendida: ";
	cin >> qtde;
	
	this->sell_product(nome, qtde);
	
	file.close();
}

void Salesman::sell_product(string nome, int qtde){
	string input;
	int qtde_anterior;
	
	ifstream read, read1;
	ofstream write, write1;

	read.open("produtos.txt");
	write.open("temp.txt");
	
	while (read >> input)
		if(input == nome){
			write << input << " "; 
			read >> input;	//executa-se duas vezes "read >> input" porque a quantidade é a segunda informação depois do nome do produto (a primeira é o modelo) 
			write << input << " ";
			read >> input; // segunda vez
			stringstream intValue(input);
			intValue >> qtde_anterior;
			qtde = qtde_anterior - qtde; 
			write << qtde << " ";
		}
		else
			write << input << " ";
			
		read.close();
	write.close();

	read1.open("Temp.txt");
	write1.open("produtos.txt");
	
	while (read1 >> input) {
    	write1 << input << " ";
	}		
}


