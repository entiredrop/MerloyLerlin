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
#include "Login.h"

using namespace std;

class Controller {
	private:
		void execute();
		bool fazerLogin();
		
		enum Estado {
			WAIT_LOGIN = 0,
			LOGGED,
			ADD_STOCK,
			CHANGE_STOCK,
			SALE
		};
		
		Estado status;
		int askOption();
		void doAction(int);
		
	public:
		Controller();
};
