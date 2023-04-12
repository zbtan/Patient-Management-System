#ifndef STATISTICREPORT_H
#define STATISTICREPORT_H

#include"Statistic.h"

class StatisticReport
{
public:
	Statistic* getGenderStat();
	Statistic* getTopMedicine();
	Statistic* getProfitYear(string date);
	Statistic* getProfitMonth(string year, string month);
	Statistic* getProfitYearInfo(string date);
	Statistic* getProfitMonthInfo(string year, string month);
};

#endif // !STATISTICREPORT_H

