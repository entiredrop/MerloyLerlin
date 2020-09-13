#include "Stock.h"

#define DEBUG false
void Stock::loadFile() {
	products.clear();
	string line; //String tempor�rio para armazenar dados de cada linha antes de jogar no vetor
	ifstream myfile ("produtos.txt"); //carrega arquivo logins.txt
	if (myfile.is_open()) //abre arquivo
	{
		try {
		while ( getline (myfile,line) ) //Vai pegando cada linha
		{
			if(DEBUG) cout << "\nTentando parse " << line << " " << line.size();
			if(line.at(0) == '-') continue;
			if(line.size() < 4) continue;
			if(DEBUG)cout << '\n' << line << '\n';
			parseProduct(line); //Carrega o usu�rio na mem�ria
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
	vector<string> productData; //Cria vetor tempor�rio de par�metros
	std::string delimiter = ","; //Define delimitador de par�metros
	
	size_t pos = 0; //Come�a na posi��o zero
	std::string token; //Par�metro a ser armazenado temporariamente
	while ((pos = s.find(delimiter)) != std::string::npos) {
	    token = s.substr(0, pos); //Procura par�metro do usu�rio
	    s.erase(0, pos + delimiter.length()); //Remove os par�metros anteriores
	    productData.push_back(token); //Insere par�metro do usu�rio no vetor tempor�rio
	    
		if(DEBUG) cout << token << std::endl;
	}
	productData.push_back(s);  //Coloca �ltimo par�metro do usu�rio
	
	if(DEBUG) cout << "\nsaiu do while, tamanho: " << products.size();
	
	//User a(login.at(0), login.at(1),login.at(2),login.at(3),login.at(4), stoi(login.at(5)), stoi(login.at(6))); //Cria um novo usu�rio
	
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

void Stock::listProducts() {
	for(int aux = 0; aux< products.size();aux++) {
		products.at(aux).get_product();
	}
} 

Produto Stock::getProduct(string nome) {
	for(int i = 0; i<products.size(); i++) {
		if(((Produto)products.at(i)).get_name() == nome) {
			return products.at(i);
		}
	}
}
