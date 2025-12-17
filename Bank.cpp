#include "Bank.h"

#include <iomanip>
#include <iostream>

/**
 * Prints the calculated results of each years investment details in 3 separate fields
 * @param t_year year number
 * @param t_yearEndBalance the current dollar value of the investment
 * @param t_interestEarned dollar amount of how much earned in that year
 */
void Bank::m_printDetails(int t_year, double t_yearEndBalance, double t_interestEarned) const {
    int width1 = M_WIDTH - (to_string(t_year).size() + to_string(t_yearEndBalance).size());
    int width2 = M_WIDTH - (to_string(t_year).size() + to_string(t_interestEarned).size());
    cout << t_year;
    cout << m_nCharString(width1, ' ');                           // align table items
    cout << "$" << fixed << setprecision(2) << t_yearEndBalance;  // round to 2 decimals
    cout << m_nCharString(width2, ' ');                           // align table items
    cout << "$" << t_interestEarned;
    cout << endl;
}

/**
 * Calculates and returns an end of year balance for given number of years
 * (without monthly deposits)
 * @param t_initialInvestment dollar amount of initial investment
 * @param t_interestRate percentage of investment earned each year (annually), so a passed value of 3.5 is a rate of .035
 * @param t_numberOfYears number of years to calculate balance for
 */
void Bank::calculateBalanceWithoutMonthlyDeposit(double t_initialInvestment, double t_interestRate, int t_numberOfYears) const {
    double totalBalance = t_initialInvestment;  // total + interest (closing balance)
    double yearInterestEarned = 0;              // end year interest earned

    cout << "Balance and Interest Without Monthly Deposits" << endl;
    cout << "Year\t\tYear End Balance\t\tInterest Earned" << endl;

    for (unsigned int i = 1; i <= t_numberOfYears; i++) {  // years
        double startYearBalance = totalBalance;
        for (unsigned int j = 1; j <= M_MONTHS; j++) {  // months
            double monthlyInterest;
            monthlyInterest = (totalBalance) * ((t_interestRate / 100.0) / 12.0);
            totalBalance += monthlyInterest;
        }
        yearInterestEarned = totalBalance - startYearBalance;
        m_printDetails(i, totalBalance, yearInterestEarned);  // display table
    }
}

/**
 * Calculates and returns an end of year balance for a given number of years
 * @param t_initialInvestment dollar amount of initial investment
 * @param t_monthlyDeposit dollar amount added into the investment each month
 * @param t_interestRate percentage of investment earned each year (annually), so a passed value of 3.5 is a rate of .035
 * @param t_numberOfYears number of years to calculate balance for
 */
void Bank::calculateBalanceWithMonthlyDeposit(double t_initialInvestment, double t_monthlyDeposit, double t_interestRate, int t_numberOfYears) const {
    double totalBalance = t_initialInvestment;             // total + interest (closing balance)
    double yearInterestEarned = 0;                         // end year interest earned
    double monthlyRate = (t_interestRate / 100.0) / 12.0;  // interest per month

    cout << "Balance and Interest With Monthly Deposits" << endl;
    cout << "Year\t\tYear End Balance\t\tInterest Earned" << endl;

    for (unsigned int i = 1; i <= t_numberOfYears; i++) {  // years
        double startYearBalance = totalBalance;
        double yearTotalDeposits = 0;
        for (unsigned int j = 1; j <= M_MONTHS; j++) {          // months
            double monthlyInterest = totalBalance * monthlyRate;  // calculate monthly compounded interest
            totalBalance += (t_monthlyDeposit + monthlyInterest);
            yearTotalDeposits += t_monthlyDeposit;
        }
        yearInterestEarned = (totalBalance - startYearBalance) - yearTotalDeposits;
        m_printDetails(i, totalBalance, yearInterestEarned);  // display table
    }
}

/**
 * Returns a string of length t_num, each character a t_char.
 * For example, nCharString(5, '*') returns "*****"
 * @param t_num string length, >=0
 * @param t_char character to make string of
 * @return string of n t_char's
 */
string Bank::m_nCharString(size_t t_num, char t_char) const {
    string charString;
    for (int i = 0; i < t_num; i++) {
        charString += t_char;
    }

    return charString;
}