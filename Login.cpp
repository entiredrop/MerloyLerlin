#include "Login.h"
#include <List>

#define DEBUG false
/*
Padr�o de usu�rios:

Usuario,Senha,Nome,Permissao
*/

vector<User> users; //Vetor de usu�rios

void Login::loadFile() {
	string line; //String tempor�rio para armazenar dados de cada linha antes de jogar no vetor
	ifstream myfile ("logins.txt"); //carrega arquivo logins.txt
	if (myfile.is_open()) //abre arquivo
	{
		while ( getline (myfile,line) ) //Vai pegando cada linha
		{
			cout << '\n' << line << '\n';
			parseLogin(line); //Carrega o usu�rio na mem�ria
		}
    	myfile.close(); //Fecha arquivo no final
	}

  else if(DEBUG) cout << "Unable to open file"; 
}

void Login::parseLogin(string s) {
	vector<string> login; //Cria vetor tempor�rio de par�metros
	std::string delimiter = ","; //Define delimitador de par�metros
	
	size_t pos = 0; //Come�a na posi��o zero
	std::string token; //Par�metro a ser armazenado temporariamente
	while ((pos = s.find(delimiter)) != std::string::npos) {
	    token = s.substr(0, pos); //Procura par�metro do usu�rio
	    s.erase(0, pos + delimiter.length()); //Remove os par�metros anteriores
	    login.push_back(token); //Insere par�metro do usu�rio no vetor tempor�rio
	    
		if(DEBUG) cout << token << std::endl;
	}
	login.push_back(s);  //Coloca �ltimo par�metro do usu�rio
	
	if(DEBUG) cout << "\nsaiu do while, tamanho: " << login.size();
	
	User a(login.at(0), login.at(1),login.at(2), stoi(login.at(3))); //Cria um novo usu�rio
	
	if(DEBUG) cout << "\nCriou usuario";
	
	users.push_back(a); //Coloca usuario na lista
	
	if(DEBUG) cout << "\nColocou usuario";
}

bool Login::TryLogin(string username) {
	//for (int i = 0; i != users.size(); ++i) 
    //    cout << users.at(1) ;
    for(int i = 0; i<users.size(); ++i) { //For para comparar se o usu�rio existe
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
