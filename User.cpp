#include "User.h"
#include <iostream>

using namespace std;

User::User() {
	this->username = "";
	this->password = "";
	this->Name = "";
	this->permission = 0;
	this->age = 0;
	this->cpf = "";
	this->gender = "";
}


User::User(string nome, string CPF, string genero, string userN, string senha, int idade, int permissao)
	
	this->username = userN;
	this->password = senha;
	this->Name = nome;
	this->permission = permissao;
	this->age = idade;
	this->cpf = CPF;
	this->gender = genero; 
} 




void User::permissao(){
	
	
	switch (this->permission){
		
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
	this->age = idade;
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









