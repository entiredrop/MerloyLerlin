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

using namespace std;

class Controller {
	private:
		void execute();
		bool fazerLogin();
		
		enum Estado {
			WAIT_LOGIN = 0,
			LOGGED = 1,
		};
		
		Estado status;
		
	public:
		Controller();
};
