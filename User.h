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

using namespace std;

class User {
	private:
		string username;
		string password;
		string Nome;
		int permission;
		
	public:
		User(string username, string password, string Nome, int permission);
		string getUsername() {return this->username;}
};
