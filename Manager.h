#include<iostream>
#include<fstream>
#include<sstream>
#include "User.h"
#include "Stockist.h"
#include "Salesman.h"

using namespace std;

class Manager: public Stockist, Salesman{
	public:
		void execute();
		void change_product();
};
