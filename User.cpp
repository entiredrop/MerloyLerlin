#include "User.h"
#include <iostream>

using namespace std;

Stock *s = s->getInstance();

#define DEBUG false

User::User() {
	if(DEBUG)cout << "Chamando construtor 1";
	this->username = "";
	this->password = "";
	this->Name = "";
	this->permission = 0;
	this->age = 0;
	this->cpf = "";
	this->gender = "";
}

//User::User(User const& usa) {
//	cout << "Chamando construtor 2";
//}

User::User(string nome, string CPF, string genero, string userN, string senha, int idade, int permissao)
{
	if(DEBUG)cout << "Chamando construtor 3";
	this->username = userN;
	this->password = senha;
	this->Name = nome;
	this->permission = permissao;
	this->age = idade;
	this->cpf = CPF;
	this->gender = genero;
	return;
} 




void User::permissao(){
	
	
	switch (this->permission){
		
		case 0 :
			cout << "\nEste usuario nao tem nenhuma permissao!\n" << endl; 
		
		case 1:
				cout << "\nEste usuario nao pode adicionar um produto!\n" << endl; 
				
		case 2:
			cout << "\nEste usuario pode adicionar um produto!\n" << endl; 
			
		case 3:
			cout << "\nEste usuario pode adicionar e editar um produto!\n" << endl;
			
		case 4:
			cout << "\nEste usuario pode adicionar, editar e remover um produto!\n" << endl; 	
	
	}
	
	
}

//GETTER's E SETTER's

//----------NAME-----------
string User::getNome(){
	
	return this->Name;
}

void User::setNome(string n){
	
	this->Name = n;
}

//----------CPF------------
string User::getcpf(){
	
	return this->cpf;
}

void User::setcpf(string C){
	this->cpf = C;
}

//----------AGE------------

int User::getIdade(){
	
	return this->age;
}

void User::setIdade(int d){
	this->age = d;
}

//------PERMISSION----------

int User::getPermissao(){
	
	return this->permission;
}

void User::setPermissao(int pm){
	
	this->permission = pm;
}

//---------GENDER-----------

string User::getGenero(){
	
	return this->gender;
}

void User::setGenero(string G){
	
	this->gender = G;
}

//---------PASSWORD----------

string User::getPassword(){
	
	return this->password;
}

void User::setSenha(string psw){
	
	this->password = psw;
}

//--------USER-NAME------------

string User::getuserName(){
	
	return this->username;
}

void User::setuserName(string nm){
	
	this->username = nm;
}

void User::listProduct() {
	s->listProducts();
}

void User::showOptions() {
}

//DESTRUTOR

User::~User(){
	
	if(DEBUG)cout << "\nEste usuario foi removido!\n" << endl;
	
}

void Salesman::remove_product(){
	string nome; //"nome de um produto" a ser procurado no arquivos "products.txt"
	int qtde; //quantidade vendida
	
	fflush(stdin);
	
	cout << "Digite o nome do produto: ";
	getline(cin, nome);
	
	//Stockist temp;
		
	while(!s->check_product(nome)){
		cout << "Produto inexistente no estoque. Digite um produto valido: ";
		getline(cin, nome);
	}
	
	cout << "Digite a quantidade vendida: ";
	cin >> qtde;
	
	s->remove_stock(nome,qtde);
	//this->sell_product(nome, qtde);
}

void Salesman::sell_product(){
	//Gravar em um arquivo a venda, produto   valor    valor total
	string nome; //"nome de um produto" a ser procurado no arquivos "products.txt"
	int qtde; //quantidade vendida
	string buyerName;
	fflush(stdin);
	
	cout << "\nDigite o nome do comprador: ";
	cin >> buyerName;
	Venda venda(buyerName, this->getNome());
	do {
		fflush(stdin);
		cout << "\nDigite o nome do produto ou digite 0 para finalizar os produtos: ";
		getline(cin, nome);
		if(nome == "0") break;
		//Stockist temp;
			
		while(!s->check_product(nome)){
			cout << "Produto inexistente no estoque. Digite um produto valido: ";
			getline(cin, nome);
			if(nome == "0") break;
		}
		if(nome == "0") break;
		
		cout << "Digite a quantidade vendida: ";
		cin >> qtde;
		
		Produto a = s->getProduct(nome);
	    venda.putProduct(a, (int)qtde);
		s->remove_stock(nome,qtde);
		
	}while(true);
	
	venda.saveSale();
	
}

void Salesman::showOptions() {
	if(this->getPermissao() == 4) {
		cout << "\n3 - Realizar Venda";
	}
	else {
		cout << "\n1 - Realizar Venda";
		cout << "\n2 - Listar produtos";
	}
}


void Stockist::add_product(){
	s->createProduct();
	return;
}

void Stockist::add_stock() {
	if(this->getPermissao() == 4) {
		
	}
	else {
	
		string nome; //"nome de um produto" a ser procurado no arquivos "produtos.txt"
		int qtde; //quantidade a ser adicionada ao estoque
		cout << "Digite o nome do produto para adicionar estoque: ";
		getline(cin, nome);
		while(!s->check_product(nome)){
			cout << "Produto inexistente, entre com um nome valido: ";
			getline(cin, nome);
		}
			
		cout << "Digite a quantidade a ser adicionada: ";
		cin >> qtde;
		s->add_stock(nome, qtde);
	}
}

void Stockist::showOptions() {
	cout << "\n1 - Criar um novo produto";
	cout << "\n2 - Alterar produto existente em estoque";
	if(this->getPermissao() != 4)
		cout << "\n3 - Listar produtos";
}

void Manager::execute(){
	int choice;
	
	cout << "1 - Criar/Alterar um produto" << endl;
	cout << "2 - Vender um produto" << endl;
	cout << "Opcao: ";
	cin >> choice;
	
	if(choice == 1)
		Stockist::add_product();
	else if(choice == 2)
		Salesman::remove_product();
	else
		cout << "Opcao invalida"<<endl;
}

void Manager::showOptions() {
	Stockist::showOptions();
	Salesman::showOptions();
	cout << "\n4 - Criar novo login";
	cout << "\n5 - Deletar login";
	cout << "\n6 - Listar produtos";
	cout << "\n7 - Listar vendas";
}

void Manager::change_product(){
	string input;
	string nome_produto, novo_nome, modelo_produto;
	int preco;
	int i, choice, qtde;
	
	cout << "1 - Alterar nome do produto" <<endl;
	cout << "2 - Alterar modelo do produto" <<endl;
	cout << "3 - Alterar quantidade do estoque do produto" <<endl;
	cout << "4 - Alterar preco do produto" <<endl;
	cout << "Opcao: ";
	cin >> choice;
	
	switch(choice){
		case 1:
			fflush(stdin);
			cout <<"Digite qual produto desejas alterar o nome: ";
			getline(cin, nome_produto);
			while(!s->check_product(nome_produto)){
				cout << "Produto inexistente. Digite novamente: ";
				getline(cin, nome_produto);
			}
			fflush(stdin);

			s->changeName(nome_produto);
			
			break;
		case 2:
			fflush(stdin);
			cout <<"Digite qual produto desejas alterar o modelo: ";
			getline(cin, nome_produto);
			while(!s->check_product(nome_produto)){
				cout << "Produto inexistente. Digite novamente: ";
				getline(cin, nome_produto);
			}
			
			fflush(stdin);
			
			s->changeModel(nome_produto);
			
			break;
		case 3:
			fflush(stdin);
			cout <<"Digite qual produto desejas alterar a quantidade: ";
			getline(cin, nome_produto);
			while(!s->check_product(nome_produto)){
				cout << "Produto inexistente. Digite novamente: ";
				getline(cin, nome_produto);
			}
			
			fflush(stdin);
			s->setAmount(nome_produto);
			break;
		case 4:
			fflush(stdin);
			cout <<"Digite qual produto desejas alterar o preco: ";
			getline(cin, nome_produto);
			while(!s->check_product(nome_produto)){
				cout << "Produto inexistente. Digite novamente: ";
				getline(cin, nome_produto);
			}
			
			fflush(stdin);
			s->setPrice(nome_produto);
	}
}

void Manager::showSales() {
//	cout << "\nShow sales 1";
	string final;
	string line; //String temporário para armazenar dados de cada linha antes de jogar no vetor
	ifstream myfile ("sales.txt"); //carrega arquivo logins.txt
	if (myfile.is_open()) //abre arquivo
	{
		try {
			while ( getline (myfile,line) ) //Vai pegando cada linha
			{
//				cout << "\nShow sales 2";
				if(DEBUG) cout << "\nTentando parse " << line << " " << line.size();
				if(line.at(0) == '-') continue;
				if(line.size() < 4) continue;
				if(DEBUG)cout << '\n' << line << '\n';
				final.append(parseSale(line)); //Carrega o usuário na memória
			}
		}
		catch(...) {
			
		}
    	myfile.close(); //Fecha arquivo no final
    	if(DEBUG) cout << "Finalizado de carregar vendas";
	}
	cout<<"\n"<<final;
}

string Manager::parseSale(string s) {
//	cout << "\nShow sales 3";
	vector<string> saleData; 										//Cria vetor temporário de parâmetros
	string delimiter = ","; 										//Define delimitador de parâmetros
		
	size_t pos = 0; 												//Começa na posição zero
	string token; 													//Parâmetro a ser armazenado temporariamente
	
	while ((pos = s.find(delimiter)) != std::string::npos) {
	    token = s.substr(0, pos); 									//Procura parâmetro da venda
	    
	    s.erase(0, pos + delimiter.length()); 						//Remove os parâmetros anteriores
//	    cout << "\nShow sales 4";
	    if(token.find("{") != string::npos) {						//Se tiver as chaves, precisa abrir os produtos
	    	token.erase(token.begin());										//Remove as chaves iniciais
			token.erase(token.end() -1);									//E as finais
	    	if(token.find(";") != string::npos) {					//Marcador que define a separacao entre produtos de uma venda
	    		//Abrir produtos
//	    		cout << "\nShow sales 5";
	    		token = parseProductList(token);
			}
			else {
				//Pegar somente um produto
//				cout << "\nShow sales 5.1";
				token = parseProductValue(token);
				
			}
	    	
	    	saleData.push_back(token);
//	    	cout << "\nShow sales 18";
		}
		else {
//			cout << "\nShow sales 19";
	    	saleData.push_back(token); 									//Insere parâmetro do usuário no vetor temporário
		}

		if(DEBUG) cout << token << std::endl;
	}
//	cout << "\nShow sales 20";
	saleData.push_back(s);  										//Coloca último parâmetro do usuário
	
	//Padrao de venda:  Comprador, vendedor, produtos, total
	string final = "  ----- Venda -----\nComprador: ";
	final.append(saleData.at(0));
	final.append("\nVendedor: ");
	final.append(saleData.at(1));
	
	final.append(saleData.at(2));
	final.append("\nTotal: RS ");
	final.append(to_string(stof(saleData.at(3))/100));
	final.append("\n\n");
	return final;
}

string Manager::parseProductList(string s) {
//	cout << "\nShow sales 6";
	vector<string> saleData; 										//Cria vetor temporário de parâmetros
	string delimiter = ";"; 										//Define delimitador de parâmetros
	
	
	
	size_t pos = 0; 												//Começa na posição zero
	string token; 													//Parâmetro a ser armazenado temporariamente
	
	while ((pos = s.find(delimiter)) != std::string::npos) {
//		cout << "\nShow sales 7";
	    token = s.substr(0, pos); 									//Procura parâmetro do usuário
	    
	    s.erase(0, pos + delimiter.length()); 						//Remove os parâmetros anteriores
	    
//	    cout << "\nShow sales 8";
	    token = parseProductValue(token);							//Abre os produtos
	    
	    saleData.push_back(token); 									//Insere parâmetro do usuário no vetor temporário
//		cout << "\nShow sales 14";
		if(DEBUG) cout << token << std::endl;
	}
//	cout << "\nShow sales 15";
	saleData.push_back(parseProductValue(s));  										//Coloca último parâmetro do usuário
	
	string final;
//	cout << "\nShow sales 16";
	for(int aux = 0;aux < saleData.size(); aux++) {
		final.append("\n");
		final.append(saleData.at(aux));
	}
//	cout << "\nShow sales 17";
	return final;
}

string Manager::parseProductValue(string s) {
//	cout << "\nShow sales 9";
	vector<string> saleData; 										//Cria vetor temporário de parâmetros
	string delimiter = ":"; 										//Define delimitador de parâmetros
	
	size_t pos = 0; 												//Começa na posição zero
	string token; 													//Parâmetro a ser armazenado temporariamente
	
	while ((pos = s.find(delimiter)) != std::string::npos) {
//		cout << "\nShow sales 10";
	    token = s.substr(0, pos); 									//Procura parâmetro do usuário
	    
	    s.erase(0, pos + delimiter.length()); 						//Remove os parâmetros anteriores
	    	    
//	    	    cout << "\nShow sales 11";
	    saleData.push_back(token); 									//Insere parâmetro do usuário no vetor temporário

		if(DEBUG) cout << token << std::endl;
	}
	saleData.push_back(s);  										//Coloca último parâmetro do usuário
	
//	cout << "\nShow sales 12";
	string final;
	final.append("\nProduto: ");
	final.append(saleData.at(0));
	final.append("\nQuantidade: ");
	final.append(saleData.at(1));
	final.append("\nSubtotal: RS ");
	final.append(to_string(stof(saleData.at(2))/100));
//	cout << "\nShow sales 13";
	return final;
}

Venda::Venda(string buyer, string seller) {
	vetor.clear();
	sale.clear();
	this->buyer = buyer;
	this->seller = seller;
}

void Venda::putProduct(Produto a, int qtd) {
	valor = valor + a.get_price()*qtd;
	//vetor.emplace_back(a);
	//int qtde= qtd;
	//sale.insert(a,qtde);
	sale[a] = qtd;
}

void Venda::saveSale() {
	
	//for(int aux = 0; aux<sale.size();aux++) {
	//	Produto a = sale.;
	//}
	ifstream read;
	read.open("sales.txt");
	ofstream write1;
 	
 	string buffer;
 	string input;
	while(!read.eof()){
		getline(read, input);
		buffer.append(input);
	}
	read.close();

	string temp = buyer;
	temp.append(",");
	temp.append(seller);
	temp.append(",{");
	//Padrao de venda: Comprador,Vendedor,{item:qtd:subtotal;item:qtd:subtotal}, total.
	for(std::map<Produto,int>::iterator it = sale.begin(); it != sale.end(); ++it) {
		Produto a = it->first;
		temp.append(a.get_name());
		temp.append(":");
		temp.append(to_string(it->second));
		temp.append(":");
		temp.append(to_string(it->second * a.get_price()));
		temp.append(";");
	}
	temp.erase(temp.end()-1);
	temp.append("},");
	temp.append(to_string(valor));
	
	buffer.append("\n");
	buffer.append(temp);
 	write1.open("sales.txt");
    write1 << buffer <<endl;
	
	
	//for(auto const& imap: sale)
    //cout << imap.first;
	
	//return temp;
}
