#include<iostream>
#include "User.h"

using namespace std;

class Stockist: public User{
	public:
		void add_product();
		bool check_product(string nome);
		void change_product(string nome, inte qtde);
};
