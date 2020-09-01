#include "Login.h"
#include "User.h"
#include <List>

#define DEBUG false
/*
Padrão de usuários:

Usuario,Senha,Nome,Permissao
*/

vector<User> users;

void Login::loadFile() {
	string line;
	ifstream myfile ("logins.txt");
	if (myfile.is_open())
	{
		while ( getline (myfile,line) )
		{
			cout << '\n' << line << '\n';
			parseLogin(line);
		}
    myfile.close();
	}

  else if(DEBUG) cout << "Unable to open file"; 
}

void Login::parseLogin(string s) {
	vector<string> login;
	std::string delimiter = ",";
	
	size_t pos = 0;
	std::string token;
	while ((pos = s.find(delimiter)) != std::string::npos) {
	    token = s.substr(0, pos);
	    if(DEBUG) std::cout << token << std::endl;
	    s.erase(0, pos + delimiter.length());
	    login.push_back(token);
	}
	login.push_back(s);
	if(DEBUG) cout << "\nsaiu do while, tamanho: " << login.size();
	
	User a(login.at(0), login.at(1),login.at(2), stoi(login.at(3)));
	
	if(DEBUG) cout << "\nCriou usuario";
	users.push_back(a);
	if(DEBUG) cout << "\nColocou usuario";
}

bool Login::TryLogin(string username) {
	//for (int i = 0; i != users.size(); ++i) 
    //    cout << users.at(1) ;
    for(int i = 0; i<users.size(); ++i) {
    	if(((User)users.at(i)).getUsername() == username) {
    		//Login existe
    		return true;
		}
	}
    return false;
}
