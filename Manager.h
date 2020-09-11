#include<iostream>
#include<fstream>
#include<sstream>
#include "Stockist.h"
#include "Salesman.h"

using namespace std;

class Manager: public Stockist, Salesman{
	public:
		void execute();
		void change_product();
};
