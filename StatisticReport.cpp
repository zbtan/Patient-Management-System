#include"DatabaseConnection.h"
#include"StatisticReport.h"

Statistic* StatisticReport::getGenderStat()
{
	DatabaseConnection dbConn;
	sql::PreparedStatement* ps = dbConn.prepareStatement("SELECT COUNT(CASE WHEN GENDER LIKE \"F%\" THEN 1 END) AS FEMALE, COUNT(CASE WHEN GENDER LIKE \"M%\" THEN 1 END) AS MALE, COUNT(*) AS TOTAL FROM patient;");
	sql::ResultSet* rs = ps->executeQuery();
	Statistic* statistic = NULL;

	if (rs->next())
	{
		statistic = new Statistic();
		statistic->female = rs->getInt("FEMALE");
		statistic->male = rs->getInt("MALE");
		statistic->totalpatient = rs->getInt("TOTAL");
	}

	rs->close();
	ps->close();

	delete rs;
	delete ps;

	return statistic;
}

Statistic* StatisticReport::getTopMedicine()
{
	DatabaseConnection dbConn;
	sql::PreparedStatement* ps = dbConn.prepareStatement("SELECT D.MEDICINE_ID, C.NAME, SUM(D.QUANTITY_REQUIRED) AS QUANTITY FROM medical_invoice_detail D INNER JOIN medicine_list C ON D.MEDICINE_ID = C.MEDICINE_ID GROUP BY D.MEDICINE_ID ORDER BY QUANTITY DESC LIMIT 3");
	sql::ResultSet* rs = ps->executeQuery();
	Statistic* statistic = NULL;
	Statistic* head = NULL;

	while (rs->next())
	{
		if (statistic == NULL)
		{
			statistic = new Statistic();
			head = statistic;
		}
		else
		{
			statistic->next = new Statistic();
			statistic = statistic->next;
		}

		statistic->medicineid = rs->getString("MEDICINE_ID");
		statistic->mediname = rs->getString("NAME");
		statistic->mediquan = rs->getInt("QUANTITY");
	}

	rs->close();
	ps->close();

	delete rs;
	delete ps;

	return head;
}

Statistic* StatisticReport::getProfitYear(string date)
{
	DatabaseConnection dbConn;
	sql::PreparedStatement* ps = dbConn.prepareStatement("SELECT COUNT(*) AS NUMBER_OF_PAYMENT, SUM(I.TOTAL_PRICE) AS PROFIT FROM medical_invoice I INNER JOIN payment_report P ON I.MEDICALIN_ID = P.MEDICALIN_ID WHERE extract(year from P.DATE_TIME) = ? ");

	ps->setString(1, date);

	sql::ResultSet* rs = ps->executeQuery();
	Statistic* statistic = NULL;

	if (rs->next())
	{
		statistic = new Statistic();
		statistic->profit = rs->getInt("PROFIT");
		statistic->numpay = rs->getInt("NUMBER_OF_PAYMENT");
	}

	rs->close();
	ps->close();

	delete rs;
	delete ps;

	return statistic;
}

Statistic* StatisticReport::getProfitMonth(string year, string month)
{
	DatabaseConnection dbConn;
	sql::PreparedStatement* ps = dbConn.prepareStatement("SELECT COUNT(*) AS NUMBER_OF_PAYMENT, SUM(I.TOTAL_PRICE) AS PROFIT FROM medical_invoice I INNER JOIN payment_report P ON I.MEDICALIN_ID = P.MEDICALIN_ID WHERE extract(year from P.DATE_TIME) = ? AND extract(month from P.DATE_TIME) = ?");

	ps->setString(1, year);
	ps->setString(2, month);

	sql::ResultSet* rs = ps->executeQuery();
	Statistic* statistic = NULL;

	if (rs->next())
	{
		statistic = new Statistic();
		statistic->profit = rs->getInt("PROFIT");
		statistic->numpay = rs->getInt("NUMBER_OF_PAYMENT");
	}

	rs->close();
	ps->close();

	delete rs;
	delete ps;

	return statistic;
}

Statistic* StatisticReport::getProfitYearInfo(string date)
{
	DatabaseConnection dbConn;
	sql::PreparedStatement* ps = dbConn.prepareStatement("SELECT P.PAYMENT_ID, P.PATIENT_ID, I.TOTAL_PRICE FROM medical_invoice I INNER JOIN payment_report P ON I.MEDICALIN_ID = P.MEDICALIN_ID WHERE extract(year from P.DATE_TIME) = ? ");

	ps->setString(1, date);
	
	sql::ResultSet* rs = ps->executeQuery();
	Statistic* statistic = NULL;
	Statistic* head = NULL;

	while (rs->next())
	{
		if (statistic == NULL)
		{
			statistic = new Statistic();
			head = statistic;
		}
		else
		{
			statistic->next = new Statistic();
			statistic = statistic->next;
		}

		statistic->paymentid = rs->getString("PAYMENT_ID");
		statistic->patientid = rs->getString("PATIENT_ID");
		statistic->price = rs->getDouble("TOTAL_PRICE");
	}

	rs->close();
	ps->close();

	delete rs;
	delete ps;

	return head;
}

Statistic* StatisticReport::getProfitMonthInfo(string date, string month)
{
	DatabaseConnection dbConn;
	sql::PreparedStatement* ps = dbConn.prepareStatement("SELECT P.PAYMENT_ID, P.PATIENT_ID, I.TOTAL_PRICE FROM medical_invoice I INNER JOIN payment_report P ON I.MEDICALIN_ID = P.MEDICALIN_ID WHERE extract(year from P.DATE_TIME) = ? AND extract(month from P.DATE_TIME) = ?");

	ps->setString(1, date);
	ps->setString(2, month);

	sql::ResultSet* rs = ps->executeQuery();
	Statistic* statistic = NULL;
	Statistic* head = NULL;

	while (rs->next())
	{
		if (statistic == NULL)
		{
			statistic = new Statistic();
			head = statistic;
		}
		else
		{
			statistic->next = new Statistic();
			statistic = statistic->next;
		}

		statistic->paymentid = rs->getString("PAYMENT_ID");
		statistic->patientid = rs->getString("PATIENT_ID");
		statistic->price = rs->getDouble("TOTAL_PRICE");
	}

	rs->close();
	ps->close();

	delete rs;
	delete ps;

	return head;
}