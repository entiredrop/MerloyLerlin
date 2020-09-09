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
		User(string nome, string CPF, string genero, string userN, string senha, int idade, int permissao);
		//User(string username, string password, string Nome, int permission);
		string getUsername() {return this->username;}
		string getPassword();
		
		
		void permissao(); // para verificar a permissão do usuário
	
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
