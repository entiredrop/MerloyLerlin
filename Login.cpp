#include "Login.h"
#include <List>

#define DEBUG false
/*
Padr�o de usu�rios:

Usuario,Senha,Nome,Permissao
*/

 //Vetor de usu�rios

void Login::loadFile() {
	users.clear();
	string line; //String tempor�rio para armazenar dados de cada linha antes de jogar no vetor
	ifstream myfile ("logins.txt"); //carrega arquivo logins.txt
	if (myfile.is_open()) //abre arquivo
	{
		while ( getline (myfile,line) ) //Vai pegando cada linha
		{
			if(line.size() <=4 ) continue;
			if(line.at(0) == '-') continue;
			if(DEBUG)cout << '\n' << line << '\n';
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
	
	//User a(login.at(0), login.at(1),login.at(2),login.at(3),login.at(4), stoi(login.at(5)), stoi(login.at(6))); //Cria um novo usu�rio
	
	if(DEBUG) cout << "\nCriou usuario";
	
	//users.emplace_back(a); //Coloca usuario na lista
	users.emplace_back(User(login.at(0), login.at(1),login.at(2),login.at(3),login.at(4), stoi(login.at(5)), stoi(login.at(6))));
	if(DEBUG) cout << "\nColocou usuario";
}

bool Login::TryLogin(string username) {
	//for (int i = 0; i != users.size(); ++i) 
    //    cout << users.at(1) ;
    if(DEBUG) cout << "\nTrylogin " << username << " tamanho users: " << users.size();
    for(int i = 0; i<users.size(); ++i) {
    	if(DEBUG) cout << "\nProcurando...";
    	if(((User)users.at(i)).getUsername() == username) {
    		if(DEBUG) cout << "ACHOU USUARIO";
    		//Login existe
    		activeUser = new User(((User)users.at(i)).getNome(), ((User)users.at(i)).getcpf(), ((User)users.at(i)).getGenero(), ((User)users.at(i)).getUsername(), ((User)users.at(i)).getPassword(), ((User)users.at(i)).getIdade(), ((User)users.at(i)).getPermissao());
    		if(DEBUG) cout << "Retornando verdadeiro";
    		return true;
		}
	}
    return false;
}

bool Login::TryPassword(string password) {
	if(activeUser->getPassword() == password) {
		logged = true;
	}
	else
		logged = false;
		
	return logged;
}

bool Login::isLogged() {
	return logged;
}

void Login::createNewLogin() {
	string nome, cpf, genero, username, password;
	int idade, permissao;
	cout << "\nDigite o nome da pessoa: ";
	cin >> nome;
	cout << "\nDigite o CPF: ";
	cin >> cpf;
	cout << "\nDigite o genero: ";
	cin >> genero;
	cout << "\nDigite o nome de usuario: ";
	cin >> username;
	cout << "\nDigite a senha: ";
	cin >> password;
	cout << "\nDigite a idade: ";
	cin >> idade;
	cout << "\nEscolha o tipo de usuario:\n1 - Nada\n2 - Vendedor\n3 - Estoquista\n4 - Gerente\nEscolha: ";
	cin >> permissao;
	
	users.emplace_back(User(nome,cpf,genero,username,password,idade,permissao));
	
	saveLogins();
}

void Login::deleteLogin() {
	string username;
	bool found = false;
	cout << "\nDigite o nome de usuario a ser deletado: ";
	do{
		cin >> username;
		if(username == "0") {
			return;
		}
		for(int i = 0; i < users.size(); i++) {
			if(users.at(i).getuserName() == username) {
				found = true;
				users.erase(users.begin() + i);
				cout << "\nUsuario deletado com sucesso! Posicao ";
				break;
			}
		}
		if(!found) {
			fflush(stdin);
			cout << "\nUsuario nao encontrado, digite 0 para sair ou tente novamente: ";
		}
	}while(!found);
	saveLogins();
}

User *Login::getUser() {
	return this->activeUser;
}

void Login::saveLogins() {
	cout << "Chamando save logins";
	string temp = "";
	for(int aux = 0;aux < users.size(); aux++) {
		User a = (User)users.at(aux);
		temp.append(a.getNome());
		temp.append(",");
		temp.append(a.getcpf());
		temp.append(",");
		temp.append(a.getGenero());
		temp.append(",");
		temp.append(a.getuserName());
		temp.append(",");
		temp.append(a.getPassword());
		temp.append(",");
		temp.append(std::to_string(a.getIdade()));
		temp.append(",");
		temp.append(std::to_string(a.getPermissao()));
		temp.append("\n");
		
	}
	
	ofstream write;

	write.open("logins.txt");

    write << temp << endl;
}

void Login::logout() {
	activeUser = new User();
	logged = false;
}
