#include <iostream>
#include "Login.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
Login *Login::instance = 0;

int main(int argc, char** argv) {
	Login *l = l->getInstance();
	if(l->TryLogin("caiocesar")) {
		cout << "\n\nDigite sua senha";
	}
	return 0;
}