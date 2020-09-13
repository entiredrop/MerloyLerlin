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
			cout << "\n Logado! abrindo permissao! " << l->getUser()->getPermissao();
			displayMenu();
			switch(l->getUser()->getPermissao()) {
				case 1:
					break;
				case 2:
					{
						Salesman a = (*l->getUser());
					}
					break;
				case 3:
					{
						Stockist a = (*l->getUser());
					}
					break;
				case 4:
					Manager a = (*l->getUser());
					a.execute();
					break;
			}
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
		cout << "\n\nDigite sua senha: ";
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

void Controller::displayMenu() {
	switch(l->getUser()->getPermissao()) {
		case 4:
			
			//fallthrough
		case 1:
			break;
		case 2:
			break;
		case 3:
			break;
		default:
			cout << "\n -> Deu ruim no displayMenu <-";
			break;
	}
}
