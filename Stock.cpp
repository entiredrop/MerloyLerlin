#include "Stock.h"

public Stock::loadFile() {
	users.clear();
	string line; //String temporário para armazenar dados de cada linha antes de jogar no vetor
	ifstream myfile ("produtos.txt"); //carrega arquivo logins.txt
	if (myfile.is_open()) //abre arquivo
	{
		while ( getline (myfile,line) ) //Vai pegando cada linha
		{
			if(line.at(0) == '-') continue;
			cout << '\n' << line << '\n';
			parseLogin(line); //Carrega o usuário na memória
		}
    	myfile.close(); //Fecha arquivo no final
	}

  else if(DEBUG) cout << "Unable to open file"; 
}

void Stock::parseProduct(string s) {
	vector<string> productData; //Cria vetor temporário de parâmetros
	std::string delimiter = ","; //Define delimitador de parâmetros
	
	size_t pos = 0; //Começa na posição zero
	std::string token; //Parâmetro a ser armazenado temporariamente
	while ((pos = s.find(delimiter)) != std::string::npos) {
	    token = s.substr(0, pos); //Procura parâmetro do usuário
	    s.erase(0, pos + delimiter.length()); //Remove os parâmetros anteriores
	    productData.push_back(token); //Insere parâmetro do usuário no vetor temporário
	    
		if(DEBUG) cout << token << std::endl;
	}
	productData.push_back(s);  //Coloca último parâmetro do usuário
	
	if(DEBUG) cout << "\nsaiu do while, tamanho: " << login.size();
	
	//User a(login.at(0), login.at(1),login.at(2),login.at(3),login.at(4), stoi(login.at(5)), stoi(login.at(6))); //Cria um novo usuário
	
	if(DEBUG) cout << "\nCriou produto";
	
	//users.emplace_back(a); //Coloca usuario na lista
	products.emplace_back(Produto(productData.at(0),productData.at(1),productData.at(2)productData.at(3)));
	if(DEBUG) cout << "\nColocou produto";
}

void Stock::add_stock(string nome, int qtd) {
	for(int i = 0; i<products.size(); i++) {
		if(((Produto)products.at(i)).get_name() == nome) {
			products.at(i) = ((Produto)products.at(i)) + qtd;
		}
	}
}

void Stock::remove_stock(string nome, int qtd) {
	for(int i = 0; i<products.size(); i++) {
		if(((Produto)products.at(i)).get_name() == nome) {
			products.at(i) = ((Produto)products.at(i)) - qtd;
		}
	}
}

void Stock::createProduct() {
	Produto temp;
	temp.set_name();
	temp.set_model();
	temp.set_stock();
	temp.set_price();
	
	products.emplace_back(temp);
}

bool Stock::check_product(string nome) {
	bool existe = false;
	for(int i = 0; i<products.size(); i++) {
		if(((Produto)products.at(i)).get_name() == nome) {
			existe = true;
		}
	}
	return existe;
}

void Stock::changeName(string nomeAtual) {
	for(int i = 0; i<products.size(); i++) {
		if(((Produto)products.at(i)).get_name() == nomeAtual) {
			products.at(i) = ((Produto)products.at(i)).set_name();
		}
	}
}

void Stock::changeModel(string nomeAtual) {
	for(int i = 0; i<products.size(); i++) {
		if(((Produto)products.at(i)).get_name() == nomeAtual) {
			products.at(i) = ((Produto)products.at(i)).set_model();
		}
	}
}

void Stock::setAmount(string nome) {
	for(int i = 0; i<products.size(); i++) {
		if(((Produto)products.at(i)).get_name() == nome) {
			products.at(i) = ((Produto)products.at(i)).set_stock();
		}
	}
}

void Stock::setPrice(string nome) {
	for(int i = 0; i<products.size(); i++) {
		if(((Produto)products.at(i)).get_name() == nome) {
			products.at(i) = ((Produto)products.at(i)).set_price();
		}
	}
}
