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
#include "User.h"

using namespace std;

class Login {
	private:
		vector<User> users;
		static Login *instance;
		string user;
		string pass;
		bool logged=false;
		
		consultUsers(string user);
		User *activeUser;
		Login() {users.clear();user="";pass="";loadFile();}
		
		void parseLogin(string s);
		
	public:
		static Login *getInstance() {
			if(!instance) {
				instance = new Login();
				return instance;
			}
			else {
				return instance;
			}
		}
		void loadFile();
		bool TryLogin(string user);
		bool TryPassword(string password);
		bool isLogged();
};
