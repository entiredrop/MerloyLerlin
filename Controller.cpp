#include "Controller.h"
#include "Login.h"

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
		}
		else {
			cout << "\nSenha incorreta!";
		}
	}
	else {
		cout << "\nUsuario inexistente!";
	}
}
