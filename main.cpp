#include <iostream>
#include "Controller.h"
//#include "Stock.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

Login *Login::instance = 0;
Stock *Stock::instance = 0;

int main(int argc, char** argv) {
	Login::getInstance();
	Stock::getInstance();
	Controller *a = new Controller();
	return 0;
}
