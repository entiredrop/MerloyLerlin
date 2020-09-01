#include "Login.h"

/*
Padrão de usuários:

Usuario,Senha,Nome,Permissao
*/

void Login::loadFile() {
	string line;
	ifstream myfile ("logins.txt");
	if (myfile.is_open())
	{
		while ( getline (myfile,line) )
		{
			cout << line << '\n';
			parseLogin(line);
		}
    myfile.close();
	}

  else cout << "Unable to open file"; 
}

void Login::parseLogin(string s) {
	vector<string> vector;
	std::string delimiter = ",";
	
	size_t pos = 0;
	std::string token;
	while ((pos = s.find(delimiter)) != std::string::npos) {
	    token = s.substr(0, pos);
	    std::cout << token << std::endl;
	    s.erase(0, pos + delimiter.length());
	    vector.push_back(token);
	}
	std::cout << s << std::endl;
}
