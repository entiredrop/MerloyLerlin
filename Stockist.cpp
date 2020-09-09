#include<iostream>
#include <fstream>
#include "User.h"
#include "Stockist.h"
#include "Produto.h"

using namespace std;

//supondo que os produtos estarão salvos no arquivo da seguinte forma: nome_produto modelo quantidade_estoque preco

void Stockist::add_product(){
	string nome; //"nome de um produto" a ser procurado no arquivos "produtos.txt"
	int qtde; //quantidade a ser adicionada ao estoque
	
	fflush(stdin);
	
	cout << "Digite o nome do produto: ";
	getline(cin, nome);
	while(!this->check_product(nome)){
		cout << "Produto inexistente, entre com um nome valido: ";
		getline(cin, nome);
		
		cout << "Digite a quantidade a ser adicionada: ";
		cin >> qtde;
		
		this->change_product(nome, qtde);
}

bool Stockist::check_product(string nome){
	ifstream file;
	string input;
	bool flag = false;
	
	file.open("produtos.txt");
	
	while(file >> input)
		if(input == nome){
			flag = true;
			break;	
		}
	return flag;
	
}

void Stockist::change_product(string nome, int qtde){
	string input;
	int qtde_anterior;
	
	ifstream read, read1;
	ofstream write, write1;

	read.open("produtos.txt");
	write.open("temp.txt");
	
	while (read >> input)
		if(input == nome){
			write << input << " "; 
			read >> input;	//executa-se duas vezes "read >> input" porque a quantidade é a segunda informação (a primeira é o modelo) depois do nome do produto
			write << input << " ";
			read >> input; // segunda vez
			stringstream intValue(input);
			intValue >> qtde_anterior;
			qtde = qtde_anterior + qtde; 
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
	else
		cout << "Entrada invalida"<<endl;
}




















