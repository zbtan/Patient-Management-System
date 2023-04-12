#ifndef ADMINISTRATOR_H
#define ADMINISTRATOR_H

#include<string>
using namespace std;

class Administrator {
public:
	string adminid;
	string name;
	string gender;
	string contactnumber;
	string email;
	string password;
	Administrator* next;

};
#endif // !ADMINISTRATOR_H

