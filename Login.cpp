#include "Login.h"
#include <List>

#define DEBUG false
/*
Padrão de usuários:

Usuario,Senha,Nome,Permissao
*/

vector<User> users; //Vetor de usuários

void Login::loadFile() {
	string line; //String temporário para armazenar dados de cada linha antes de jogar no vetor
	ifstream myfile ("logins.txt"); //carrega arquivo logins.txt
	if (myfile.is_open()) //abre arquivo
	{
		while ( getline (myfile,line) ) //Vai pegando cada linha
		{
			cout << '\n' << line << '\n';
			parseLogin(line); //Carrega o usuário na memória
		}
    	myfile.close(); //Fecha arquivo no final
	}

  else if(DEBUG) cout << "Unable to open file"; 
}

void Login::parseLogin(string s) {
	vector<string> login; //Cria vetor temporário de parâmetros
	std::string delimiter = ","; //Define delimitador de parâmetros
	
	size_t pos = 0; //Começa na posição zero
	std::string token; //Parâmetro a ser armazenado temporariamente
	while ((pos = s.find(delimiter)) != std::string::npos) {
	    token = s.substr(0, pos); //Procura parâmetro do usuário
	    s.erase(0, pos + delimiter.length()); //Remove os parâmetros anteriores
	    login.push_back(token); //Insere parâmetro do usuário no vetor temporário
	    
		if(DEBUG) cout << token << std::endl;
	}
	login.push_back(s);  //Coloca último parâmetro do usuário
	
	if(DEBUG) cout << "\nsaiu do while, tamanho: " << login.size();
	
	User a(login.at(0), login.at(1),login.at(2), stoi(login.at(3))); //Cria um novo usuário
	
	if(DEBUG) cout << "\nCriou usuario";
	
	users.push_back(a); //Coloca usuario na lista
	
	if(DEBUG) cout << "\nColocou usuario";
}

bool Login::TryLogin(string username) {
	//for (int i = 0; i != users.size(); ++i) 
    //    cout << users.at(1) ;
    for(int i = 0; i<users.size(); ++i) { //For para comparar se o usuário existe
    	if(((User)users.at(i)).getUsername() == username) {
    		//Login existe
    		activeUser = (User)users.at(i);
    		return true;
		}
	}
    return false;
}

bool Login::TryPassword(string password) {
	if(activeUser.getPassword() == password) {
		logged = true;
	}
	else
		logged = false;
		
	return logged;
}

bool Login::isLogged() {
	return logged;
}
