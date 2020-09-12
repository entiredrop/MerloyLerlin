#include "Stock.h"

#define DEBUG true
void Stock::loadFile() {
	products.clear();
	string line; //String temporário para armazenar dados de cada linha antes de jogar no vetor
	ifstream myfile ("produtos.txt"); //carrega arquivo logins.txt
	if (myfile.is_open()) //abre arquivo
	{
		try {
		while ( getline (myfile,line) ) //Vai pegando cada linha
		{
			if(DEBUG) cout << "\nTentando parse " << line << " " << line.size();
			if(line.at(0) == '-') continue;
			if(line.size() < 4) continue;
			cout << '\n' << line << '\n';
			parseProduct(line); //Carrega o usuário na memória
		}
		}
		catch(...) {
			
		}
    	myfile.close(); //Fecha arquivo no final
    	if(DEBUG) cout << "Finalizado de carregar produtos";
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
	
	if(DEBUG) cout << "\nsaiu do while, tamanho: " << products.size();
	
	//User a(login.at(0), login.at(1),login.at(2),login.at(3),login.at(4), stoi(login.at(5)), stoi(login.at(6))); //Cria um novo usuário
	
	if(DEBUG) cout << "\nCriou produto";
	
	//users.emplace_back(a); //Coloca usuario na lista
	products.emplace_back(Produto(productData.at(0),productData.at(1),stoi(productData.at(2)),stof(productData.at(3))));
	if(DEBUG) cout << "\nColocou produto";
}

void Stock::add_stock(string nome, int qtd) {
	for(int i = 0; i<products.size(); i++) {
		if(((Produto)products.at(i)).get_name() == nome) {
			products.at(i) = ((Produto)products.at(i)) + qtd;
		}
	}
	saveStock();
}

void Stock::remove_stock(string nome, int qtd) {
	for(int i = 0; i<products.size(); i++) {
		if(((Produto)products.at(i)).get_name() == nome) {
			products.at(i) = ((Produto)products.at(i)) - qtd;
		}
	}
	saveStock();
}

void Stock::createProduct() {
	Produto temp;
	temp.set_name();
	temp.set_model();
	temp.set_stock();
	temp.set_price();
	
	products.emplace_back(temp);
	saveStock();
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
	saveStock();
}

void Stock::changeModel(string nomeAtual) {
	for(int i = 0; i<products.size(); i++) {
		if(((Produto)products.at(i)).get_name() == nomeAtual) {
			products.at(i) = ((Produto)products.at(i)).set_model();
		}
	}
	saveStock();
}

void Stock::setAmount(string nome) {
	for(int i = 0; i<products.size(); i++) {
		if(((Produto)products.at(i)).get_name() == nome) {
			products.at(i) = ((Produto)products.at(i)).set_stock();
		}
	}
	saveStock();
}

void Stock::setPrice(string nome) {
	for(int i = 0; i<products.size(); i++) {
		if(((Produto)products.at(i)).get_name() == nome) {
			products.at(i) = ((Produto)products.at(i)).set_price();
		}
	}
	saveStock();
}

void Stock::saveStock() {
	cout << "Chamando save stock";
	string temp = "";
	for(int aux = 0;aux < products.size(); aux++) {
		Produto a = (Produto)products.at(aux);
		temp.append(a.get_name());
		temp.append(",");
		temp.append(a.get_model());
		temp.append(",");
		temp.append(std::to_string(a.get_stock()));
		temp.append(",");
		temp.append(std::to_string(a.get_price()));
		temp.append("\n");
		
	}
	
	ofstream write;

	write.open("produtos.txt");

    write << temp << endl;
}
