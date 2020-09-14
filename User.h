#pragma once
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <math.h>
#include <map>
#include "Stock.h"

using namespace std;

class User {
	private:
		string username;
		string password;
		string Name;
		int permission;
		
		//string name;
		int age;	
		string cpf;
		string gender;

		
	public:
		User();
		//User(User const&);
		User(string nome, string CPF, string genero, string userN, string senha, int idade, int permissao);
		//User(string username, string password, string Nome, int permission);
		string getUsername() {return this->username;}
		string getPassword();
		
		
		void permissao(); // para verificar a permissão do usuário
		void listProduct();
		virtual void showOptions();
	
		//GETTER E SETTER PARA CADA ATRIBUTO
		string getNome();
		void setNome(string n);
		
		string getcpf();
		void setcpf(string C);
		
		string getGenero();
		void setGenero(string G);
		
		string getuserName();
		void setuserName(string nm);
		
		string getSenha();
		void setSenha(string psw);
		
		int getIdade();
		void setIdade(int id);
		
		int getPermissao();
		void setPermissao(int pm);
		
		
		//DESTRUTOR:
		~User();
};

class Salesman: public User{
	public:
		void remove_product();
		void sell_product();
		void showOptions();
		Salesman() : User() {
		}
		Salesman(User &a) : User(a){
		};
};

class Stockist: public User{
	public:
		void add_product();
		void add_stock();
		void showOptions();
		
		Stockist(User &a) : User(a){
		}
		Stockist():User(){
		};
};

class Manager: public Stockist, public Salesman{
	private:
		string parseSale(string);
		string parseProductList(string);
		string parseProductValue(string);
	public:
		void execute();
		void change_product();
		void showOptions();
		void showSales();
		void listProduct() {
			Salesman::listProduct();
		}
		Manager() : Stockist(),Salesman(){
		} 
		Manager(User a) : Stockist(a), Salesman(a){
		}
};

class Venda {
	private:
		int valor = 0;
		map<Produto, int> sale;
		string buyer;
		string seller;
	public:
		Venda(string,string);
		vector<Produto> vetor;
		void putProduct(Produto, int);
		void saveSale();
};
