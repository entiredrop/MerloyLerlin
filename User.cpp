#include "User.h"
#include <iostream>

using namespace std;

Stock *s = s->getInstance();

#define DEBUG false

User::User() {
	if(DEBUG)cout << "Chamando construtor 1";
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
	if(DEBUG)cout << "Chamando construtor 3";
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

void User::listProduct() {
	s->listProducts();
}

void User::showOptions() {
}

//DESTRUTOR

User::~User(){
	
	if(DEBUG)cout << "\nEste usuario foi removido!\n" << endl;
	
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

void Salesman::sell_product(){
	//Gravar em um arquivo a venda, produto   valor    valor total
	string nome; //"nome de um produto" a ser procurado no arquivos "products.txt"
	int qtde; //quantidade vendida
	string buyerName;
	fflush(stdin);
	
	cout << "\nDigite o nome do comprador: ";
	cin >> buyerName;
	Venda venda(buyerName, this->getNome());
	do {
		fflush(stdin);
		cout << "\nDigite o nome do produto ou digite 0 para finalizar os produtos: ";
		getline(cin, nome);
		if(nome == "0") break;
		//Stockist temp;
			
		while(!s->check_product(nome)){
			cout << "Produto inexistente no estoque. Digite um produto valido: ";
			getline(cin, nome);
			if(nome == "0") break;
		}
		if(nome == "0") break;
		
		cout << "Digite a quantidade vendida: ";
		cin >> qtde;
		
		Produto a = s->getProduct(nome);
	    venda.putProduct(a, (int)qtde);
		s->remove_stock(nome,qtde);
		
	}while(true);
	
	venda.saveSale();
	
}

void Salesman::showOptions() {
	if(this->getPermissao() == 4) {
		cout << "\n3 - Realizar Venda";
	}
	else {
		cout << "\n1 - Realizar Venda";
		cout << "\n2 - Listar produtos";
	}
}


void Stockist::add_product(){
	s->createProduct();
	return;
}

void Stockist::add_stock() {
	if(this->getPermissao() == 4) {
		
	}
	else {
	
		string nome; //"nome de um produto" a ser procurado no arquivos "produtos.txt"
		int qtde; //quantidade a ser adicionada ao estoque
		cout << "Digite o nome do produto para adicionar estoque: ";
		getline(cin, nome);
		while(!s->check_product(nome)){
			cout << "Produto inexistente, entre com um nome valido: ";
			getline(cin, nome);
		}
			
		cout << "Digite a quantidade a ser adicionada: ";
		cin >> qtde;
		s->add_stock(nome, qtde);
	}
}

void Stockist::showOptions() {
	cout << "\n1 - Criar um novo produto";
	cout << "\n2 - Alterar produto existente em estoque";
	if(this->getPermissao() != 4)
		cout << "\n3 - Listar produtos";
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

void Manager::showOptions() {
	Stockist::showOptions();
	Salesman::showOptions();
	cout << "\n4 - Criar novo login";
	cout << "\n5 - Deletar login";
	cout << "\n6 - Listar produtos";
}

void Manager::change_product(){
	string input;
	string nome_produto, novo_nome, modelo_produto;
	float preco;
	int i, choice, qtde;
	
	cout << "1 - Alterar nome do produto" <<endl;
	cout << "2 - Alterar modelo do produto" <<endl;
	cout << "3 - Alterar quantidade do estoque do produto" <<endl;
	cout << "4 - Alterar preco do produto" <<endl;
	cout << "Opcao: ";
	cin >> choice;
	
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
			while(!s->check_product(nome_produto)){
				cout << "Produto inexistente. Digite novamente: ";
				getline(cin, nome_produto);
			}
			
			fflush(stdin);
			s->setPrice(nome_produto);
	}
}

Venda::Venda(string buyer, string seller) {
	vetor.clear();
	sale.clear();
	this->buyer = buyer;
	this->seller = seller;
}

void Venda::putProduct(Produto a, int qtd) {
	valor = valor + a.get_price()*qtd;
	//vetor.emplace_back(a);
	//int qtde= qtd;
	//sale.insert(a,qtde);
	sale[a] = qtd;
}

void Venda::saveSale() {
	
	//for(int aux = 0; aux<sale.size();aux++) {
	//	Produto a = sale.;
	//}
	ifstream read;
	read.open("sales.txt");
	ofstream write1;
 	
 	string buffer;
 	string input;
	while(!read.eof()){
		getline(read, input);
		buffer.append(input);
	}
 	
	read.close();

	string temp = buyer;
	temp.append(",");
	temp.append(seller);
	temp.append(",{");
	
	//Padrao de venda: Comprador,Vendedor,{item:qtd:subtotal;item:qtd:subtotal}, total.
	for(std::map<Produto,int>::iterator it = sale.begin(); it != sale.end(); ++it) {
		Produto a = it->first;
		temp.append(a.get_name());
		temp.append(":");
		temp.append(to_string(it->second));
		temp.append(":");
		temp.append(to_string(it->second * a.get_price()));
		temp.append(";");
	}
	temp.erase(temp.end());
	
	temp.append("},");
	temp.append(to_string(valor));
	
 	write1.open("sales.txt");
	
    write1 << temp <<endl;
	
	
	//for(auto const& imap: sale)
    //cout << imap.first;
	
	//return temp;
}
