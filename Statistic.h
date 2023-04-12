#ifndef STATISTIC_H
#define STATISTIC_H

#include<string>
using namespace std;

class Statistic
{
public:
	int totalpatient;
	int female;
	int male;
	string medicineid;
	string mediname;
	int mediquan;
	int profit;
	int numpay;
	string paymentid;
	string patientid;
	double price;
	Statistic* next;
};

#endif

//SELECT COUNT(CASE WHEN P.GENDER LIKE "M%" AND A.DATE_TIME LIKE "2022-12%" THEN 1 END) AS MALE FROM patient P INNER JOIN appointment_list A ON P.PATIENT_ID = A.PATIENT_ID;
//SELECT SUM(I.TOTAL_PRICE) AS PROFIT FROM medical_invoice I INNER JOIN payment_report P ON I.MEDICALIN_ID = P.MEDICALIN_ID;
//SELECT D.MEDICINE_ID, C.NAME, SUM(D.QUANTITY_REQUIRED) AS QUANTITY FROM medical_invoice_detail D INNER JOIN medicine_list C ON D.MEDICINE_ID = C.MEDICINE_ID GROUP BY D.MEDICINE_ID ORDER BY QUANTITY DESC LIMIT 3;