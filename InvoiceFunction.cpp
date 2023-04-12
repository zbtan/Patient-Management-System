#include"DatabaseConnection.h"
#include"InvoiceFunction.h"

void transform(sql::ResultSet* rs, MedicalInvoice* medicalinvoice)
{
	medicalinvoice->medicalinid = rs->getString("MEDICALIN_ID");
	medicalinvoice->totalprice = rs->getDouble("TOTAL_PRICE");
	medicalinvoice->patientid = rs->getString("PATIENT_ID");
	medicalinvoice->medicalrid = rs->getString("MEDICALR_ID");
	medicalinvoice->status = rs->getInt("STATUS");
}

int InvoiceFunction::addInvoice(MedicalInvoice* medicalinvoice)
{
	DatabaseConnection dbConn;
	sql::PreparedStatement* ps = dbConn.prepareStatement("INSERT INTO medical_invoice (MEDICALIN_ID, TOTAL_PRICE, PATIENT_ID, MEDICALR_ID, STATUS) VALUES (?, ?, ?, ?, ?)");

	ps->setString(1, medicalinvoice->medicalinid);
	ps->setDouble(2, medicalinvoice->totalprice);
	ps->setString(3, medicalinvoice->patientid);
	ps->setString(4, medicalinvoice->medicalrid);
	ps->setInt(5, medicalinvoice->status);

	int numRowsAffected = ps->executeUpdate();

	ps->close();

	delete ps;

	return numRowsAffected;
}

int InvoiceFunction::updateInvoice(MedicalInvoice* medicalinvoice)
{
	DatabaseConnection dbConn;
	sql::PreparedStatement* ps = dbConn.prepareStatement("UPDATE medical_invoice SET TOTAL_PRICE = ?, PATIENT_ID = ?, MEDICALR_ID = ?, STATUS = ? WHERE MEDICALIN_ID = ?");

	ps->setDouble(1, medicalinvoice->totalprice);
	ps->setString(2, medicalinvoice->patientid);
	ps->setString(3, medicalinvoice->medicalrid);
	ps->setInt(4, medicalinvoice->status);
	ps->setString(5, medicalinvoice->medicalinid);
	
	int numRowsAffected = ps->executeUpdate();

	ps->close();

	delete ps;

	return numRowsAffected;
}

int InvoiceFunction::updateInvoicePrice(MedicalInvoice* medicalinvoice) {
	DatabaseConnection dbConn;
	sql::PreparedStatement* ps = dbConn.prepareStatement("UPDATE medical_invoice SET TOTAL_PRICE = ? WHERE MEDICALIN_ID = ?");

	ps->setDouble(1, medicalinvoice->totalprice);
	ps->setString(2, medicalinvoice->medicalinid);

	int numRowsAffected = ps->executeUpdate();

	ps->close();

	delete ps;

	return numRowsAffected;
}

int InvoiceFunction::deleteInvoice(MedicalInvoice* medicalinvoice)
{
	DatabaseConnection dbConn;
	sql::PreparedStatement* ps = dbConn.prepareStatement("DELETE FROM medical_invoice WHERE MEDICALIN_ID = ?");

	ps->setString(1, medicalinvoice->medicalinid);

	int numRowsAffected = ps->executeUpdate();

	ps->close();

	delete ps;

	return numRowsAffected;
}

MedicalInvoice* InvoiceFunction::getInvoice(string medicalinid)
{
	DatabaseConnection dbConn;
	sql::PreparedStatement* ps = dbConn.prepareStatement("SELECT * FROM medical_invoice WHERE MEDICALIN_ID = ?");

	ps->setString(1, medicalinid);

	sql::ResultSet* rs = ps->executeQuery();
	MedicalInvoice* medicalinvoice = NULL;

	if (rs->next())
	{
		medicalinvoice = new MedicalInvoice();
		transform(rs, medicalinvoice);
	}

	rs->close();
	ps->close();

	delete rs;
	delete ps;

	return medicalinvoice;
}

MedicalInvoice* InvoiceFunction::getInvoiceRID(string medicalrid) {
	DatabaseConnection dbConn;
	sql::PreparedStatement* ps = dbConn.prepareStatement("SELECT * FROM medical_invoice WHERE MEDICALR_ID = ?");

	ps->setString(1, medicalrid);

	sql::ResultSet* rs = ps->executeQuery();
	MedicalInvoice* medicalinvoice = NULL;

	if (rs->next())
	{
		medicalinvoice = new MedicalInvoice();
		transform(rs, medicalinvoice);
	}

	rs->close();
	ps->close();

	delete rs;
	delete ps;

	return medicalinvoice;
}

MedicalInvoice* InvoiceFunction::getInvoices()
{
	DatabaseConnection dbConn;
	sql::PreparedStatement* ps = dbConn.prepareStatement("SELECT * FROM medical_invoice");
	sql::ResultSet* rs = ps->executeQuery();
	MedicalInvoice* medicalinvoice = NULL;
	MedicalInvoice* head = NULL;

	while (rs->next())
	{
		if (medicalinvoice == NULL)
		{
			medicalinvoice = new MedicalInvoice();
			head = medicalinvoice;
		}
		else
		{
			medicalinvoice->next = new MedicalInvoice();
			medicalinvoice = medicalinvoice->next;
		}

		transform(rs, medicalinvoice);
	}

	rs->close();
	ps->close();

	delete rs;
	delete ps;

	return head;
}

MedicalInvoice* InvoiceFunction::getInvoiceID()
{
	DatabaseConnection dbConn;
	sql::PreparedStatement* ps = dbConn.prepareStatement("SELECT * FROM medical_invoice ORDER BY MEDICALIN_ID DESC LIMIT 1");
	sql::ResultSet* rs = ps->executeQuery();
	MedicalInvoice* medicalinvoice = NULL;

	if (rs->next())
	{
		medicalinvoice = new MedicalInvoice();
		medicalinvoice->medicalinid = rs->getString("MEDICALIN_ID");
	}

	rs->close();
	ps->close();

	delete rs;
	delete ps;

	return medicalinvoice;
}

MedicalInvoice* InvoiceFunction::getPrice(string medicalinid)
{
	DatabaseConnection dbConn;
	sql::PreparedStatement* ps = dbConn.prepareStatement("SELECT TOTAL_PRICE FROM medical_invoice WHERE MEDICALIN_ID = ?");

	ps->setString(1, medicalinid);

	sql::ResultSet* rs = ps->executeQuery();
	MedicalInvoice* medicalinvoice = NULL;

	if (rs->next())
	{
		medicalinvoice = new MedicalInvoice();
		medicalinvoice->totalprice = rs->getInt("TOTAL_PRICE");
	}

	rs->close();
	ps->close();

	delete rs;
	delete ps;

	return medicalinvoice;
}

MedicalInvoice* InvoiceFunction::getOpenInvoice()
{
	DatabaseConnection dbConn;
	sql::PreparedStatement* ps = dbConn.prepareStatement("SELECT * FROM medical_invoice WHERE STATUS = 0");
	sql::ResultSet* rs = ps->executeQuery();
	MedicalInvoice* medicalinvoice = NULL;
	MedicalInvoice* head = NULL;

	while (rs->next())
	{
		if (medicalinvoice == NULL)
		{
			medicalinvoice = new MedicalInvoice();
			head = medicalinvoice;
		}
		else
		{
			medicalinvoice->next = new MedicalInvoice();
			medicalinvoice = medicalinvoice->next;
		}

		transform(rs, medicalinvoice);
	}

	rs->close();
	ps->close();

	delete rs;
	delete ps;

	return head;
}

MedicalInvoice* InvoiceFunction::getCloseInvoice()
{
	DatabaseConnection dbConn;
	sql::PreparedStatement* ps = dbConn.prepareStatement("SELECT * FROM medical_invoice WHERE STATUS = 1");
	sql::ResultSet* rs = ps->executeQuery();
	MedicalInvoice* medicalinvoice = NULL;
	MedicalInvoice* head = NULL;

	while (rs->next())
	{
		if (medicalinvoice == NULL)
		{
			medicalinvoice = new MedicalInvoice();
			head = medicalinvoice;
		}
		else
		{
			medicalinvoice->next = new MedicalInvoice();
			medicalinvoice = medicalinvoice->next;
		}

		transform(rs, medicalinvoice);
	}

	rs->close();
	ps->close();

	delete rs;
	delete ps;

	return head;
}