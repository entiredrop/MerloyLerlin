#include "User.h"

User::User() {
	this->username = "";
	this->password = "";
	this->Nome = "";
	this->permission = 0;
}

User::User(string username, string password, string Nome, int permission) {
	this->username = username;
	this->password = password;
	this->Nome = Nome;
	this->permission = permission;
} 
