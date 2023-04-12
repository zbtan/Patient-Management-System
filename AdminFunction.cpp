#include"DatabaseConnection.h"
#include"AdminFunction.h"

void transform(sql::ResultSet* rs, Administrator* admin)
{
	admin->adminid = rs->getString("ADMIN_ID");
	admin->name = rs->getString("NAME");
	admin->gender = rs->getString("GENDER");
	admin->contactnumber = rs->getString("CONTACT_NUMBER");
	admin->email = rs->getString("EMAIL");
}

void transformA(sql::ResultSet* rs, Administrator* admin)
{
	admin->adminid = rs->getString("ADMIN_ID");
	admin->name = rs->getString("NAME");
	admin->gender = rs->getString("GENDER");
	admin->contactnumber = rs->getString("CONTACT_NUMBER");
	admin->email = rs->getString("EMAIL");
	admin->password = rs->getString("PASSWORD");
}

Administrator* AdminFunction::getAdmin(string adminid)
{
	DatabaseConnection dbConn;
	sql::PreparedStatement* ps = dbConn.prepareStatement("SELECT * FROM administrator WHERE ADMIN_ID = ?");

	ps->setString(1, adminid);

	sql::ResultSet* rs = ps->executeQuery();
	Administrator* admin = NULL;

	if (rs->next())
	{
		admin = new Administrator();
		transformA(rs, admin);
	}

	rs->close();
	ps->close();

	delete rs;
	delete ps;

	return admin;
}

Administrator* AdminFunction::getAdmins()
{
	DatabaseConnection dbConn;
	sql::PreparedStatement* ps = dbConn.prepareStatement("SELECT * FROM administrator");
	sql::ResultSet* rs = ps->executeQuery();
	Administrator* admin = NULL;
	Administrator* head = NULL;

	while (rs->next())
	{
		if (admin == NULL)
		{
			admin = new Administrator();
			head = admin;
		}
		else
		{
			admin->next = new Administrator();
			admin = admin->next;
		}

		transform(rs, admin);
	}

	rs->close();
	ps->close();

	delete rs;
	delete ps;

	return head;
}

bool AdminFunction::LoginAdmin(string id, string password) {
	DatabaseConnection dbConn;
	bool name;
	sql::PreparedStatement* ps = dbConn.prepareStatement("SELECT * FROM administrator WHERE ADMIN_ID = ? AND PASSWORD = ?");

	ps->setString(1, id);
	ps->setString(2, password);

	sql::ResultSet* rs = ps->executeQuery();
	Administrator* admin = NULL;

	if (rs->next())
	{
		name = true;
	}
	else
	{
		name = false;
	}

	rs->close();
	ps->close();

	delete rs;
	delete ps;

	return name;
}