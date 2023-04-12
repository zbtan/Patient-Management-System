#include"DatabaseConnection.h"
#include"MedicationFunction.h"

void transform(sql::ResultSet* rs, Medication* medication)
{
	medication->medicationid = rs->getString("MEDICINE_ID");
	medication->name = rs->getString("NAME");
	medication->detail = rs->getString("DETAIL");
	medication->unit = rs->getString("UNIT");
	medication->uPrice = rs->getInt("UNIT_PRICE");
	medication->adminid = rs->getString("ADMIN_ID");
}

int MedicationFunction::addMedication(Medication* medication)
{
	DatabaseConnection dbConn;
	sql::PreparedStatement* ps = dbConn.prepareStatement("INSERT INTO medicine_list (MEDICINE_ID, NAME, DETAIL, UNIT, UNIT_PRICE, ADMIN_ID) VALUES (?, ?, ?, ?, ?, ?)");

	ps->setString(1, medication->medicationid);
	ps->setString(2, medication->name);
	ps->setString(3, medication->detail);
	ps->setString(4, medication->unit);
	ps->setInt(5, medication->uPrice);
	ps->setString(6, medication->adminid);

	int numRowsAffected = ps->executeUpdate();

	ps->close();

	delete ps;

	return numRowsAffected;
}

int MedicationFunction::updateMedication(Medication* medication)
{
	DatabaseConnection dbConn;
	sql::PreparedStatement* ps = dbConn.prepareStatement("UPDATE medicine_list SET NAME = ?, DETAIL = ?, UNIT = ?, UNIT_PRICE = ?, ADMIN_ID = ? WHERE MEDICINE_ID = ?");

	ps->setString(1, medication->name);
	ps->setString(2, medication->detail);
	ps->setString(3, medication->unit);
	ps->setInt(4, medication->uPrice);
	ps->setString(5, medication->adminid);
	ps->setString(6, medication->medicationid);

	int numRowsAffected = ps->executeUpdate();

	ps->close();

	delete ps;

	return numRowsAffected;
}

int MedicationFunction::updateMedicationName(Medication* medication) {
	DatabaseConnection dbConn;
	sql::PreparedStatement* ps = dbConn.prepareStatement("UPDATE medicine_list SET NAME = ?, ADMIN_ID = ? WHERE MEDICINE_ID = ?");

	ps->setString(1, medication->name);
	ps->setString(2, medication->adminid);
	ps->setString(3, medication->medicationid);

	int numRowsAffected = ps->executeUpdate();

	ps->close();

	delete ps;

	return numRowsAffected;
}

int MedicationFunction::updateMedicationDetail(Medication* medication) {
	DatabaseConnection dbConn;
	sql::PreparedStatement* ps = dbConn.prepareStatement("UPDATE medicine_list SET DETAIL = ?, ADMIN_ID = ? WHERE MEDICINE_ID = ?");

	ps->setString(1, medication->detail);
	ps->setString(2, medication->adminid);
	ps->setString(3, medication->medicationid);

	int numRowsAffected = ps->executeUpdate();

	ps->close();

	delete ps;

	return numRowsAffected;
}

int MedicationFunction::updateMedicationUnit(Medication* medication) {
	DatabaseConnection dbConn;
	sql::PreparedStatement* ps = dbConn.prepareStatement("UPDATE medicine_list SET UNIT = ?, ADMIN_ID = ? WHERE MEDICINE_ID = ?");

	ps->setString(1, medication->unit);
	ps->setString(2, medication->adminid);
	ps->setString(3, medication->medicationid);

	int numRowsAffected = ps->executeUpdate();

	ps->close();

	delete ps;

	return numRowsAffected;
}

int MedicationFunction::updateMedicationPrice(Medication* medication) {
	DatabaseConnection dbConn;
	sql::PreparedStatement* ps = dbConn.prepareStatement("UPDATE medicine_list SET UNIT_PRICE = ?, ADMIN_ID = ? WHERE MEDICINE_ID = ?");

	ps->setInt(1, medication->uPrice);
	ps->setString(2, medication->adminid);
	ps->setString(3, medication->medicationid);

	int numRowsAffected = ps->executeUpdate();

	ps->close();

	delete ps;

	return numRowsAffected;
}

int MedicationFunction::deleteMedication(Medication* medication)
{
	DatabaseConnection dbConn;
	sql::PreparedStatement* ps = dbConn.prepareStatement("DELETE FROM medicine_list WHERE MEDICINE_ID = ?");

	ps->setString(1, medication->medicationid);

	int numRowsAffected = ps->executeUpdate();

	ps->close();

	delete ps;

	return numRowsAffected;
}

Medication* MedicationFunction::getMedication(string medicationid)
{
	DatabaseConnection dbConn;
	sql::PreparedStatement* ps = dbConn.prepareStatement("SELECT * FROM medicine_list WHERE MEDICINE_ID = ?");

	ps->setString(1, medicationid);

	sql::ResultSet* rs = ps->executeQuery();
	Medication* medication = NULL;

	if (rs->next())
	{
		medication = new Medication();
		transform(rs, medication);
	}

	rs->close();
	ps->close();

	delete rs;
	delete ps;

	return medication;
}

Medication* MedicationFunction::getMedications()
{
	DatabaseConnection dbConn;
	sql::PreparedStatement* ps = dbConn.prepareStatement("SELECT * FROM medicine_list");
	sql::ResultSet* rs = ps->executeQuery();
	Medication* medication = NULL;
	Medication* head = NULL;

	while (rs->next())
	{
		if (medication == NULL)
		{
			medication = new Medication();
			head = medication;
		}
		else
		{
			medication->next = new Medication();
			medication = medication->next;
		}

		transform(rs, medication);
	}

	rs->close();
	ps->close();

	delete rs;
	delete ps;

	return head;
}

Medication* MedicationFunction::getMedicationID()
{
	DatabaseConnection dbConn;
	sql::PreparedStatement* ps = dbConn.prepareStatement("SELECT * FROM medicine_list ORDER BY MEDICINE_ID DESC LIMIT 1");
	sql::ResultSet* rs = ps->executeQuery();
	Medication* medication = NULL;

	if (rs->next())
	{
		medication = new Medication();
		medication->medicationid = rs->getString("MEDICINE_ID");
	}

	rs->close();
	ps->close();

	delete rs;
	delete ps;

	return medication;
}