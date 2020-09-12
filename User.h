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
		User(User const&);
		User(string nome, string CPF, string genero, string userN, string senha, int idade, int permissao);
		//User(string username, string password, string Nome, int permission);
		string getUsername() {return this->username;}
		string getPassword();
		
		
		void permissao(); // para verificar a permiss�o do usu�rio
	
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
		void sell_product(string nome, int qtde);
		Salesman() : User() {
		}
		Salesman(User &a) : User(a){
		};
};

class Stockist: public User{
	public:
		void add_product();
		bool check_product(string nome);
		void add_stock(string nome, int qtde);
		Stockist(User &a) : User(a){
		}
		Stockist():User(){
		};
};

class Manager: public Stockist, Salesman{
	public:
		void execute();
		void change_product();
		Manager() : Stockist(),Salesman(){
		} 
		Manager(User a) : Stockist(a), Salesman(a){
		}
};
