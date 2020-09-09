#include<iostream>
#include "User.h"

using namespace std;

class Salesman: public User{
	public:
		void remove_product();
		void sell_product(string nome, int qtde);
};
