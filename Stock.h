#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <math.h>
#include <fstream>
#include "Produto.h"

class Stock {
	private:
		vector<Produto> products;
		static Stock *instance;
		Stock() { products.clear(); loadFile();}
		void loadFile();
		void parseProduct(string);
		
	public:
		static Stock *getInstance() {
			if(!instance) {
				instance = new Stock();
				return instance;
			}
			else {
				return instance;
			}
		}
		void add_stock(string nome, int qtd);
		void remove_stock(string nome, int qtd);
		void createProduct();
		void changeName(string);
		bool check_product(string);
		void changeModel(string);
		void setAmount(string);
		void setPrice(string);
		
		void saveStock();
};
