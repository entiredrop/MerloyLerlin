#include<iostream>
#include "Manager.h"

using namespace std;

void Manager::execute(){
	int choice;
	
	cout << "01 - Adicionar um produto" << endl;
	cout << "02 - Vender um produto" << endl;
	cout << "Opcao: ";
	cin >> choice;
	
	if(choice == 1)
		Stockist::add_product();
	else if(choice == 2)
		Salesman::remove_product();
	else
		cout << "Opcao invalida"<<endl;
}
