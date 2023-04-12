#include"DatabaseConnection.h"
#include"InvoiceDetailFunction.h"

void transform(sql::ResultSet* rs, InvoiceDetail* invoicedetail)
{
	invoicedetail->medicalindeid = rs->getString("MEDICALINDE_ID");
	invoicedetail->quantityrequired = rs->getInt("QUANTITY_REQUIRED");
	invoicedetail->medicalinid = rs->getString("MEDICALIN_ID");
	invoicedetail->medicationid = rs->getString("MEDICINE_ID");
}

int InvoiceDetailFunction::addInvoiceDetail(InvoiceDetail* invoicedetail)
{
	DatabaseConnection dbConn;
	sql::PreparedStatement* ps = dbConn.prepareStatement("INSERT INTO medical_invoice_detail (MEDICALINDE_ID, QUANTITY_REQUIRED, MEDICALIN_ID, MEDICINE_ID) VALUES (?, ?, ?, ?)");

	ps->setString(1, invoicedetail->medicalindeid);
	ps->setInt(2, invoicedetail->quantityrequired);
	ps->setString(3, invoicedetail->medicalinid);
	ps->setString(4, invoicedetail->medicationid);

	int numRowsAffected = ps->executeUpdate();

	ps->close();

	delete ps;

	return numRowsAffected;
}

int InvoiceDetailFunction::updateInvoiceDetail(InvoiceDetail* invoicedetail)
{
	DatabaseConnection dbConn;
	sql::PreparedStatement* ps = dbConn.prepareStatement("UPDATE medical_invoice_detail SET QUANTITY_REQUIRED = ?, MEDICALIN_ID = ?, MEDICINE_ID = ? WHERE MEDICALINDE_ID = ?");

	ps->setInt(1, invoicedetail->quantityrequired);
	ps->setString(2, invoicedetail->medicalinid);
	ps->setString(3, invoicedetail->medicationid);
	ps->setString(4, invoicedetail->medicalindeid);

	int numRowsAffected = ps->executeUpdate();

	ps->close();

	delete ps;

	return numRowsAffected;
}

int InvoiceDetailFunction::updateInvoiceDetailMedicine(InvoiceDetail* invoicedetail) {
	DatabaseConnection dbConn;
	sql::PreparedStatement* ps = dbConn.prepareStatement("UPDATE medical_invoice_detail SET QUANTITY_REQUIRED = ?, MEDICINE_ID = ? WHERE MEDICALINDE_ID = ?");

	ps->setInt(1, invoicedetail->quantityrequired);
	ps->setString(2, invoicedetail->medicationid);
	ps->setString(3, invoicedetail->medicalindeid);

	int numRowsAffected = ps->executeUpdate();

	ps->close();

	delete ps;

	return numRowsAffected;
}

int InvoiceDetailFunction::deleteInvoiceDetail(InvoiceDetail* invoicedetail)
{
	DatabaseConnection dbConn;
	sql::PreparedStatement* ps = dbConn.prepareStatement("DELETE FROM medical_invoice_detail WHERE MEDICALINDE_ID = ?");

	ps->setString(1, invoicedetail->medicalindeid);

	int numRowsAffected = ps->executeUpdate();

	ps->close();

	delete ps;

	return numRowsAffected;
}

InvoiceDetail* InvoiceDetailFunction::getInvoiceDetail(string medicalindeid)
{
	DatabaseConnection dbConn;
	sql::PreparedStatement* ps = dbConn.prepareStatement("SELECT * FROM medical_invoice_detail WHERE MEDICALINDE_ID = ?");

	ps->setString(1, medicalindeid);

	sql::ResultSet* rs = ps->executeQuery();
	InvoiceDetail* invoicedetail = NULL;

	if (rs->next())
	{
		invoicedetail = new InvoiceDetail();
		transform(rs, invoicedetail);
	}

	rs->close();
	ps->close();

	delete rs;
	delete ps;

	return invoicedetail;
}

InvoiceDetail* InvoiceDetailFunction::getInvoiceDetails()
{
	DatabaseConnection dbConn;
	sql::PreparedStatement* ps = dbConn.prepareStatement("SELECT * FROM medical_invoice_detail");
	sql::ResultSet* rs = ps->executeQuery();
	InvoiceDetail* invoicedetail = NULL;
	InvoiceDetail* head = NULL;

	while (rs->next())
	{
		if (invoicedetail == NULL)
		{
			invoicedetail = new InvoiceDetail();
			head = invoicedetail;
		}
		else
		{
			invoicedetail->next = new InvoiceDetail();
			invoicedetail = invoicedetail->next;
		}

		transform(rs, invoicedetail);
	}

	rs->close();
	ps->close();

	delete rs;
	delete ps;

	return head;
}

InvoiceDetail* InvoiceDetailFunction::getInvoiceDetailID()
{
	DatabaseConnection dbConn;
	sql::PreparedStatement* ps = dbConn.prepareStatement("SELECT * FROM medical_invoice_detail ORDER BY MEDICALINDE_ID DESC LIMIT 1");
	sql::ResultSet* rs = ps->executeQuery();
	InvoiceDetail* invoicedetail = NULL;

	if (rs->next())
	{
		invoicedetail = new InvoiceDetail();
		invoicedetail->medicalindeid = rs->getString("MEDICALINDE_ID");
	}

	rs->close();
	ps->close();

	delete rs;
	delete ps;

	return invoicedetail;
}

InvoiceDetail* InvoiceDetailFunction::getInvoiceDetailMI(string medicalinid)
{
	DatabaseConnection dbConn;
	sql::PreparedStatement* ps = dbConn.prepareStatement("SELECT * FROM medical_invoice_detail WHERE MEDICALIN_ID = ?");

	ps->setString(1, medicalinid);

	sql::ResultSet* rs = ps->executeQuery();
	InvoiceDetail* invoicedetail = NULL;
	InvoiceDetail* head = NULL;

	while (rs->next())
	{
		if (invoicedetail == NULL)
		{
			invoicedetail = new InvoiceDetail();
			head = invoicedetail;
		}
		else
		{
			invoicedetail->next = new InvoiceDetail();
			invoicedetail = invoicedetail->next;
		}

		transform(rs, invoicedetail);
	}

	rs->close();
	ps->close();

	delete rs;
	delete ps;

	return head;
}