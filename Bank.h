#ifndef BANK_H
#define BANK_H
#include <string>
using namespace std;

class Bank {
public:
    void calculateBalanceWithoutMonthlyDeposit(double t_initialInvestment, double t_interestRate, int t_numberOfYears) const;
    void calculateBalanceWithMonthlyDeposit(
        double t_initialInvestment,
        double t_monthlyDeposit,
        double t_interestRate,
        int t_numberOfYears) const;

private:
    const int M_WIDTH = 35;   // table width
    const int M_MONTHS = 12;  // 12 months in a year
    string m_nCharString(size_t t_num, char t_char) const;
    void m_printDetails(int t_year, double t_yearEndBalance, double t_interestEarned) const;
};

#endif