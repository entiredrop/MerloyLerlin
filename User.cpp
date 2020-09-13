#include "User.h"
#include <iostream>

using namespace std;

Stock *s = s->getInstance();

User::User() {
	cout << "Chamando construtor 1";
	this->username = "";
	this->password = "";
	this->Name = "";
	this->permission = 0;
	this->age = 0;
	this->cpf = "";
	this->gender = "";
}

//User::User(User const& usa) {
//	cout << "Chamando construtor 2";
//}

User::User(string nome, string CPF, string genero, string userN, string senha, int idade, int permissao)
{
	cout << "Chamando construtor 3";
	this->username = userN;
	this->password = senha;
	this->Name = nome;
	this->permission = permissao;
	this->age = idade;
	this->cpf = CPF;
	this->gender = genero;
	return;
} 




void User::permissao(){
	
	
	switch (this->permission){
		
		case 0 :
			cout << "\nEste usuario nao tem nenhuma permissao!\n" << endl; 
		
		case 1:
				cout << "\nEste usuario nao pode adicionar um produto!\n" << endl; 
				
		case 2:
			cout << "\nEste usuario pode adicionar um produto!\n" << endl; 
			
		case 3:
			cout << "\nEste usuario pode adicionar e editar um produto!\n" << endl;
			
		case 4:
			cout << "\nEste usuario pode adicionar, editar e remover um produto!\n" << endl; 	
	
	}
	
	
}

//GETTER's E SETTER's

//----------NAME-----------
string User::getNome(){
	
	return this->Name;
}

void User::setNome(string n){
	
	this->Name = n;
}

//----------CPF------------
string User::getcpf(){
	
	return this->cpf;
}

void User::setcpf(string C){
	this->cpf = C;
}

//----------AGE------------

int User::getIdade(){
	
	return this->age;
}

void User::setIdade(int d){
	this->age = d;
}

//------PERMISSION----------

int User::getPermissao(){
	
	return this->permission;
}

void User::setPermissao(int pm){
	
	this->permission = pm;
}

//---------GENDER-----------

string User::getGenero(){
	
	return this->gender;
}

void User::setGenero(string G){
	
	this->gender = G;
}

//---------PASSWORD----------

string User::getPassword(){
	
	return this->password;
}

void User::setSenha(string psw){
	
	this->password = psw;
}

//--------USER-NAME------------

string User::getuserName(){
	
	return this->username;
}

void User::setuserName(string nm){
	
	this->username = nm;
}


//DESTRUTOR

User::~User(){
	
	cout << "\nEste usuario foi removido!\n" << endl;
	
}

void Salesman::remove_product(){
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
		s->createProduct();
		
		//temp.save_product();
	}
	
	else if(choice == 2){
		cout << "Digite o nome do produto: ";
		getline(cin, nome);
		while(!s->check_product(nome)){
			cout << "Produto inexistente, entre com um nome valido: ";
			getline(cin, nome);
		}
		
			cout << "Digite a quantidade a ser adicionada: ";
			cin >> qtde;
			s->add_stock(nome, qtde);
			//this->add_stock(nome, qtde);
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

void Stockist::add_stock(string nome, int qtde){
	
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

void Manager::execute(){
	int choice;
	
	cout << "1 - Criar/Alterar um produto" << endl;
	cout << "2 - Vender um produto" << endl;
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
			while(!s->check_product(nome_produto)){
				cout << "Produto inexistente. Digite novamente: ";
				getline(cin, nome_produto);
			}
			fflush(stdin);

			s->changeName(nome_produto);
			
			break;
		case 2:
			fflush(stdin);
			cout <<"Digite qual produto desejas alterar o modelo: ";
			getline(cin, nome_produto);
			while(!s->check_product(nome_produto)){
				cout << "Produto inexistente. Digite novamente: ";
				getline(cin, nome_produto);
			}
			
			fflush(stdin);
			
			s->changeModel(nome_produto);
			
			break;
		case 3:
			fflush(stdin);
			cout <<"Digite qual produto desejas alterar a quantidade: ";
			getline(cin, nome_produto);
			while(!s->check_product(nome_produto)){
				cout << "Produto inexistente. Digite novamente: ";
				getline(cin, nome_produto);
			}
			
			fflush(stdin);
			s->setAmount(nome_produto);
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
			s->setPrice(nome_produto);
	}
		
		/*	
	read.close();
	write.close();

	read1.open("temp.txt");
	write1.open("produtos.txt");

	while (!read1.eof()){
		getline(read1, input);
    	write1 << input << endl;
	}
	*/
}







