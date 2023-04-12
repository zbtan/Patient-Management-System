#include"DatabaseConnection.h"
#include"PaymentFunction.h"

void transform(sql::ResultSet* rs, PaymentReport* paymentreport)
{
	paymentreport->paymentid = rs->getString("PAYMENT_ID");
	paymentreport->datetime = rs->getString("DATE_TIME");
	paymentreport->totalprice = rs->getDouble("TOTAL_PRICE");
	paymentreport->totalpayment = rs->getDouble("TOTAL_PAYMENT");
	paymentreport->totalchange = rs->getDouble("TOTAL_CHANGE");
	paymentreport->patientid = rs->getString("PATIENT_ID");
	paymentreport->medicalinid = rs->getString("MEDICALIN_ID");
}

int PaymentFunction::addPaymentReport(PaymentReport* paymentreport)
{
	DatabaseConnection dbConn;
	sql::PreparedStatement* ps = dbConn.prepareStatement("INSERT INTO payment_report (PAYMENT_ID, DATE_TIME, TOTAL_PAYMENT, TOTAL_CHANGE, PATIENT_ID, MEDICALIN_ID, TOTAL_PRICE) VALUES (?, ?, ?, ?, ?, ?, ?)");

	ps->setString(1, paymentreport->paymentid);
	ps->setString(2, paymentreport->datetime);
	ps->setInt(3, paymentreport->totalpayment);
	ps->setInt(4, paymentreport->totalchange);
	ps->setString(5, paymentreport->patientid);
	ps->setString(6, paymentreport->medicalinid);
	ps->setDouble(7, paymentreport->totalprice);

	int numRowsAffected = ps->executeUpdate();

	ps->close();

	delete ps;

	return numRowsAffected;
}

int PaymentFunction::updatePaymentReport(PaymentReport* paymentreport)
{
	DatabaseConnection dbConn;
	sql::PreparedStatement* ps = dbConn.prepareStatement("UPDATE payment_report SET DATE_TIME = ?, TOTAL_PAYMENT = ?, TOTAL_CHANGE = ?, PATIENT_ID = ?, MEDICALIN_ID = ?, TOTAL_PRICE = ? WHERE PAYMENT_ID = ?");

	ps->setString(1, paymentreport->datetime);
	ps->setInt(2, paymentreport->totalpayment);
	ps->setInt(3, paymentreport->totalchange);
	ps->setString(4, paymentreport->patientid);
	ps->setString(5, paymentreport->medicalinid);
	ps->setDouble(6, paymentreport->totalprice);
	ps->setString(7, paymentreport->paymentid);

	int numRowsAffected = ps->executeUpdate();

	ps->close();

	delete ps;

	return numRowsAffected;
}

int PaymentFunction::deletePaymentReport(PaymentReport* paymentreport)
{
	DatabaseConnection dbConn;
	sql::PreparedStatement* ps = dbConn.prepareStatement("DELETE FROM payment_report WHERE PAYMENT_ID = ?");

	ps->setString(1, paymentreport->paymentid);

	int numRowsAffected = ps->executeUpdate();

	ps->close();

	delete ps;

	return numRowsAffected;
}

PaymentReport* PaymentFunction::getPaymentReport(string paymentid)
{
	DatabaseConnection dbConn;
	sql::PreparedStatement* ps = dbConn.prepareStatement("SELECT * FROM payment_report WHERE PAYMENT_ID = ?");

	ps->setString(1, paymentid);

	sql::ResultSet* rs = ps->executeQuery();
	PaymentReport* paymentreport = NULL;

	if (rs->next())
	{
		paymentreport = new PaymentReport();
		transform(rs, paymentreport);
	}

	rs->close();
	ps->close();

	delete rs;
	delete ps;

	return paymentreport;
}

PaymentReport* PaymentFunction::getPaymentReports()
{
	DatabaseConnection dbConn;
	sql::PreparedStatement* ps = dbConn.prepareStatement("SELECT * FROM payment_report");
	sql::ResultSet* rs = ps->executeQuery();
	PaymentReport* paymentreport = NULL;
	PaymentReport* head = NULL;

	while (rs->next())
	{
		if (paymentreport == NULL)
		{
			paymentreport = new PaymentReport();
			head = paymentreport;
		}
		else
		{
			paymentreport->next = new PaymentReport();
			paymentreport = paymentreport->next;
		}

		transform(rs, paymentreport);
	}

	rs->close();
	ps->close();

	delete rs;
	delete ps;

	return head;
}

PaymentReport* PaymentFunction::getPaymentID()
{
	DatabaseConnection dbConn;
	sql::PreparedStatement* ps = dbConn.prepareStatement("SELECT * FROM payment_report ORDER BY PAYMENT_ID DESC LIMIT 1");
	sql::ResultSet* rs = ps->executeQuery();
	PaymentReport* paymentreport = NULL;

	if (rs->next())
	{
		paymentreport = new PaymentReport();
		paymentreport->paymentid = rs->getString("PAYMENT_ID");
	}

	rs->close();
	ps->close();

	delete rs;
	delete ps;

	return paymentreport;
}