#ifndef PAYMENTFUNCTION_H
#define PAYMENTFUNCTION_H

#include"PaymentReport.h"

class PaymentFunction {
public:
	int addPaymentReport(PaymentReport* paymentreport);
	int updatePaymentReport(PaymentReport* paymentreport);
	int deletePaymentReport(PaymentReport* paymentreport);
	PaymentReport* getPaymentReport(string paymentid);
	PaymentReport* getPaymentReports();
	PaymentReport* getPaymentID();
};
#endif // !PAYMENTFUNCTION_H

