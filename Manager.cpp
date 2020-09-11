#include<iostream>
#include "Manager.h"

using namespace std;

void Manager::execute(){
	int choice;
	
	cout << "01 - Adicionar um produto" << endl;
	cout << "02 - Vender um produto" << endl;
	cout << "Opcao: ";
	cin >> choice;
	
	if(choice == 1)
		Stockist::add_product();
	else if(choice == 2)
		Salesman::remove_product();
	else
		cout << "Opcao invalida"<<endl;
}

void Manager::change_product(){
	string input;
	string nome_produto, novo_nome, modelo_produto;
	float preco;
	int i, choice, qtde;
	
	cout << "01 - Alterar nome do produto" <<endl;
	cout << "02 - Alterar modelo do produto" <<endl;
	cout << "03 - Alterar quantidade do estoque do produto" <<endl;
	cout << "04 - Alterar preco do produto" <<endl;
	cout << "Opcao: ";
	cin >> choice;
	
	ifstream read, read1;
	ofstream write, write1;

	read.open("produtos.txt");
	write.open("temp.txt");
	
	switch(choice){
		case 1:
			fflush(stdin);
			cout <<"Digite qual produto desejas alterar o nome: ";
			getline(cin, nome_produto);
			while(!this->check_product(nome_produto)){
				cout << "Produto inexistente. Digite novamente: ";
				getline(cin, nome_produto);
			}
			fflush(stdin);
			cout << "Digite o novo nome para o produto: ";
			getline(cin,novo_nome);
			
			while(!read.eof()){
				getline(read, input);
				if(input == nome_produto){
					write << novo_nome << endl;
				}
				else
					write << input << endl;
				}
			break;
		case 2:
			fflush(stdin);
			cout <<"Digite qual produto desejas alterar o modelo: ";
			getline(cin, nome_produto);
			while(!this->check_product(nome_produto)){
				cout << "Produto inexistente. Digite novamente: ";
				getline(cin, nome_produto);
			}
			
			fflush(stdin);
			cout << "Digite o novo modelo para o produto: ";
			getline(cin,novo_nome);
			
			while(!read.eof()){
				getline(read, input);
				if(input == nome_produto){
					write << input << endl;
					getline(read, input);
					write << novo_nome << endl;
				}
				else
					write << input << endl;
				}
			break;
		case 3:
			fflush(stdin);
			cout <<"Digite qual produto desejas alterar a quantidade: ";
			getline(cin, nome_produto);
			while(!this->check_product(nome_produto)){
				cout << "Produto inexistente. Digite novamente: ";
				getline(cin, nome_produto);
			}
			
			fflush(stdin);
			cout << "Digite a nova quantidade para o produto: ";
			cin >> qtde;
			
			while(!read.eof()){
				getline(read, input);
				if(input == nome_produto){
					write << input << endl;
					getline(read, input);
					write << input << endl;
					getline(read, input);
					write << qtde << endl;
				}
				else
					write << input << endl;
			}
			break;
		case 4:
			fflush(stdin);
			cout <<"Digite qual produto desejas alterar o preco: ";
			getline(cin, nome_produto);
			while(!this->check_product(nome_produto)){
				cout << "Produto inexistente. Digite novamente: ";
				getline(cin, nome_produto);
			}
			
			fflush(stdin);
			cout << "Digite a nova quantidade para o produto: ";
			cin >> preco;
			
			while(!read.eof()){
				getline(read, input);
				if(input == nome_produto){
					write << input << endl;
					getline(read, input);
					write << input << endl;
					getline(read, input);
					write << input << endl;
					getline(read, input);
					write << preco << endl;
				}
				else
					write << input << endl;
			}
	}
			
	read.close();
	write.close();

	read1.open("temp.txt");
	write1.open("produtos.txt");

	while (!read1.eof()){
		getline(read1, input);
    	write1 << input << endl;
	}
}


