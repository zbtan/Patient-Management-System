#ifndef ADMINFUNCTION_H
#define ADMINFUNCTION_H

#include"Administrator.h"

class AdminFunction {
public:
	Administrator* getAdmin(string adminid);
	Administrator* getAdmins();
	bool LoginAdmin(string id, string password);
};
#endif // !ADMINFUNCTION_H

