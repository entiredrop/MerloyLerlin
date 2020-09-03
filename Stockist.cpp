#include<iostream>
#include "Stockist.h"
#include "Product.h"

using namespace std;

void Stockist::add_product(){
	int choice;
	string nome; //"nome de um produto" a ser procurado no arquivos "products.txt"
	int qtde; //quantidade a ser adicionada ao estoque
	Product temp;
	//ifstream myfile ("products.txt"); //carrega arquivo products.txt
	cout << "01 - Criar novo produto" <<endl;
	cout << "02 - Alterar a quantidade do produto" <<endl;
	cout << "Opcao: ";
	cin >> choice;
	if(choice == 1){
		cout << "Digite o nome do produto: ";
		cin >> temp.nome_produto;
		cout << "Digite o modelo do produto: ";
		cin >> temp.modelo;
		cout << "Digite a quantidade do produto: ";
		cin >> temp.quantidade_estoque;
		cout << "Digite o preco produto: ";
		cin >> temp.preco;
		temp(nome_produto,modelo,quantidade_estoque,preco);
	}
	else if(choice == 2){
		cout << "Digite o nome do produto: ";
		cin >> nome;
		//algoritmo de procura no arquivo pelo produto
		cout << "Digite a quantidade a ser adicionada: ";
		cin >> qtde;
		temp += qtde;
	}
	else
		cout << "Entrada invalida"<<endl;
}

