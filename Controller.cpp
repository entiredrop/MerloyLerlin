#include "Controller.h"


Login *l = l->getInstance();

Controller::Controller() {
	status = WAIT_LOGIN;
	this->execute();
}

void Controller::execute() {
	switch(status) {
		case WAIT_LOGIN: {
				do {
					fazerLogin();
				}
				while(!l->isLogged());
			break;
		}
		case LOGGED: {
			//Mostrar menu
			//cout << "\n Logado! abrindo permissao! " << l->getUser()->getPermissao();
			//displayMenu();
			//l->createNewLogin();
			//l->deleteLogin();
			cout << "\n\n --- Menu Principal --- ";

			switch(l->getUser()->getPermissao()) {
				case 1:
					{
						User a = (*l->getUser());
						cout << "\n Usuario Comum: " << a.getNome();
						cout << "\n\n0 - Logout";
						a.showOptions();
						int option = askOption();
						if(option == 0) {
							l->logout();
							status = WAIT_LOGIN;
						}
						if(option == 1) {
							a.listProduct();
						}
					}
					break;
				case 2:
					{
						Salesman a = (*l->getUser());
						cout << "\n Vendedor: " << a.getNome();
						cout << "\n\n0 - Logout";
						a.showOptions();
						int option = askOption();
						if(option == 0) {
							l->logout();
							status = WAIT_LOGIN;
						}
						if(option == 1) {
							a.sell_product();
						}
						else if(option == 2) {
							a.listProduct();
						}
					}
					break;
				case 3:
					{
						Stockist a = (*l->getUser());
						cout << "\n Estoquista: " << a.getNome();
						cout << "\n\n0 - Logout";
						a.showOptions();
						int option = askOption();
						switch (option) {
							case 0:
								l->logout();
								status = WAIT_LOGIN;
								break;
							case 1:
								a.add_product();
								break;
							case 2:
								a.add_stock();
								break;
							case 3:
								a.listProduct();
								break;
						}
					}
					break;
				case 4:
					{
						Manager a = (*l->getUser());
						cout << "\n Gerente: " << l->getUser()->getNome();
						cout << "\n\n0 - Logout";
						a.showOptions();
						int option = askOption();
						
							switch (option) {
								case 0:
									l->logout();
									status = WAIT_LOGIN;
									break;
								case 1:
									a.add_product();
									break;
								case 2:
									a.change_product();
									break;
								case 3:
									a.sell_product();
									break;
								case 4:
									l->createNewLogin();
									break;
								case 5:
									l->deleteLogin();
									break;
								case 6:
									a.listProduct();
									break;
								case 7:
									a.showSales();
									break;
							}
						
					}
					break;
			}
			execute();
			
			//Manager a;
			//a.execute();
			break;
		}
	}
}

bool Controller::fazerLogin() {
	fflush(stdin);
	cout << "\nDigite o seu usuario: ";
	string var;
	cin >> var;
	if(l->TryLogin(var)) {
		cout << "\nDigite sua senha: ";
		var = "";
		fflush(stdin);
		cin >> var;
		if(l->TryPassword(var)) {
			cout << "\nLogado!";
			status = LOGGED;
			execute();
		}
		else {
			cout << "\nSenha incorreta!";
		}
	}
	else {
		cout << "\nUsuario inexistente!";
	}
}

int Controller::askOption() {
	int option;
	cout << "\nSelecione uma opcao: ";
	cin >> option;
	return option;
}

void Controller::doAction(int option) {
	switch(l->getUser()->getPermissao()) {
				case 1:
					break;
				case 2:
					{
						Salesman a = (*l->getUser());
						a.showOptions();
						int option = askOption();
					}
					break;
				case 3:
					{
						Stockist a = (*l->getUser());
						a.showOptions();
						int option = askOption();
					}
					break;
				case 4:
					{
						Manager a = (*l->getUser());
						a.showOptions();
						int option = askOption();
					}
					break;
			}
}
