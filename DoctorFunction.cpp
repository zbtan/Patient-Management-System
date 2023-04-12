#include"DatabaseConnection.h"
#include"DoctorFunction.h"

void transform(sql::ResultSet* rs, Doctor* doctor)
{
	doctor->doctorid = rs->getString("DOCTOR_ID");
	doctor->name = rs->getString("NAME");
	doctor->gender = rs->getString("GENDER");
	doctor->contactnumber = rs->getString("CONTACT_NUMBER");
	doctor->email = rs->getString("EMAIL");
	doctor->expertisefield = rs->getString("EXPERTISE_FIELD");
	doctor->adminid = rs->getString("ADMIN_ID");	
}

Doctor* DoctorFunction::getDoctorI(string doctorid)
{
	DatabaseConnection dbConn;
	sql::PreparedStatement* ps = dbConn.prepareStatement("SELECT * FROM doctor WHERE DOCTOR_ID = ?");

	ps->setString(1, doctorid);

	sql::ResultSet* rs = ps->executeQuery();
	Doctor* doctor = NULL;

	if (rs->next())
	{
		doctor = new Doctor();
		transform(rs, doctor);
	}

	rs->close();
	ps->close();

	delete rs;
	delete ps;

	return doctor;
}

Doctor* DoctorFunction::getDoctorN(string name)
{
	DatabaseConnection dbConn;
	sql::PreparedStatement* ps = dbConn.prepareStatement("SELECT * FROM doctor WHERE NAME = ?");

	ps->setString(1, name);

	sql::ResultSet* rs = ps->executeQuery();
	Doctor* doctor = NULL;

	if (rs->next())
	{
		doctor = new Doctor();
		transform(rs, doctor);
	}

	rs->close();
	ps->close();

	delete rs;
	delete ps;

	return doctor;
}

Doctor* DoctorFunction::getDoctors()
{
	DatabaseConnection dbConn;
	sql::PreparedStatement* ps = dbConn.prepareStatement("SELECT * FROM doctor");
	sql::ResultSet* rs = ps->executeQuery();
	Doctor* doctor = NULL;
	Doctor* head = NULL;

	while (rs->next())
	{
		if (doctor == NULL)
		{
			doctor = new Doctor();
			head = doctor;
		}
		else
		{
			doctor->next = new Doctor();
			doctor = doctor->next;
		}

		transform(rs, doctor);
	}

	rs->close();
	ps->close();

	delete rs;
	delete ps;

	return head;
}

bool DoctorFunction::loginDoc(string id, string password) {
	DatabaseConnection dbConn;
	bool name;
	sql::PreparedStatement* ps = dbConn.prepareStatement("SELECT * FROM doctor WHERE DOCTOR_ID = ? AND PASSWORD = ?");

	ps->setString(1, id);
	ps->setString(2, password);

	sql::ResultSet* rs = ps->executeQuery();
	Doctor* doctor = NULL;

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