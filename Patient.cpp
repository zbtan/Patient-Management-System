#include "DatabaseConnection.h"
#include "Patient.h"

void transform(sql::ResultSet* rs, Patient* patient)
{
	patient->patientid = rs->getString("Patient_ID");
	patient->name = rs->getString("Name");
	patient->gender = rs->getString("Gender");
	patient->birth = rs->getString("Date_of_Birth");
	patient->icnumber = rs->getInt("IC_Number");
	patient->address = rs->getString("Address");
	patient->contactnumber = rs->getInt("Contact_Number");
	patient->econtactnumber = rs->getInt("Emergency_Contact_Number");
	patient->email = rs->getString("Email");
	patient->adminid = rs->getString("Admin_ID");
}

int Patient::addPatient(Patient* patient)
{
	DatabaseConnection dbConn;
	sql::PreparedStatement* ps = dbConn.prepareStatement("INSERT INTO Patient (Patient_ID, Name, Gender, Date_of_Birth, IC_Number, Address, Contact_Number, Emergency_Contact_Number, Email, Admin_ID) VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?, ?)");

	ps->setString(1, patient->patientid);
	ps->setString(2, patient->name);
	ps->setString(3, patient->gender);
	ps->setString(4, patient->birth);
	ps->setInt(5, patient->icnumber);
	ps->setString(6, patient->address);
	ps->setInt(7, patient->contactnumber);
	ps->setInt(8, patient->econtactnumber);
	ps->setString(9, patient->email);
	ps->setString(10, patient->adminid);

	int numRowsAffected = ps->executeUpdate();

	ps->close();

	delete ps;

	return numRowsAffected;
}

int Patient::updatePatient(Patient* patient)
{
	DatabaseConnection dbConn;
	sql::PreparedStatement* ps = dbConn.prepareStatement("UPDATE Patient SET Name = ?, Gender = ?, Date_of_Birth = ?, IC_Number = ?, Address = ?, Contact_Number = ?, Emergency_Contact_Number = ?, Email = ?, Admin_ID = ? WHERE Patient_ID = ?");

	ps->setString(1, patient->name);
	ps->setString(2, patient->gender);
	ps->setString(3, patient->birth);
	ps->setInt(4, patient->icnumber);
	ps->setString(5, patient->address);
	ps->setInt(6, patient->contactnumber);
	ps->setInt(7, patient->econtactnumber);
	ps->setString(8, patient->email);
	ps->setString(9, patient->adminid);
	ps->setString(10, patient->patientid);

	int numRowsAffected = ps->executeUpdate();

	ps->close();

	delete ps;

	return numRowsAffected;
}

int Patient::deletePatient(Patient* patient)
{
	DatabaseConnection dbConn;
	sql::PreparedStatement* ps = dbConn.prepareStatement("DELETE FROM Patient WHERE Patient_ID = ?");

	ps->setString(1, patient->patientid);

	int numRowsAffected = ps->executeUpdate();

	ps->close();

	delete ps;

	return numRowsAffected;
}

Patient* Patient::getPatient(string patientid)
{
	DatabaseConnection dbConn;
	sql::PreparedStatement* ps = dbConn.prepareStatement("SELECT * FROM Patient WHERE Patient_ID = ?");

	ps->setString(1, patientid);

	sql::ResultSet* rs = ps->executeQuery();
	Patient* patient = NULL;

	if (rs->next())
	{
		patient = new Patient();
		transform(rs, patient);
	}

	rs->close();
	ps->close();

	delete rs;
	delete ps;

	return patient;
}

Patient* Patient::getPatients()
{
	DatabaseConnection dbConn;
	sql::PreparedStatement* ps = dbConn.prepareStatement("SELECT * FROM Car");
	sql::ResultSet* rs = ps->executeQuery();
	Patient* patient = NULL;
	Patient* head = NULL;

	while (rs->next())
	{
		if (patient == NULL)
		{
			patient = new Patient();
			head = patient;
		}
		else
		{
			patient->next = new Patient();
			patient = patient->next;
		}

		transform(rs, patient);
	}

	rs->close();
	ps->close();

	delete rs;
	delete ps;

	return head;
}