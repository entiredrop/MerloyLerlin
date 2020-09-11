#include<iostream>
#include "User.h"
#include "Stock.h"

using namespace std;

class Stockist: public User{
	public:
		void add_product();
		bool check_product(string nome);
		void add_stock(string nome, int qtde);
};
