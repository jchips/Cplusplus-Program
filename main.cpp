/* Jaye Rhinehart */

#include <iostream>

#include "Bank.h"
using namespace std;

int main() {
    Bank userBank;
    double initialInvestment;
    double monthlyDeposit;
    double interestRate;
    int numberOfYears;
    bool continueAirgeadBanking = true;

    while (continueAirgeadBanking) {
        cout << "Initial Investment Amount: $";
        cin >> initialInvestment;
        cout << "Monthly Deposit: $";
        cin >> monthlyDeposit;
        cout << "Annual Interest: %";
        cin >> interestRate;
        cout << "Number of Years: ";
        cin >> numberOfYears;
        cout << endl;

        /* Balance and Interest Without Monthly Deposits table */
        userBank.calculateBalanceWithoutMonthlyDeposit(
            initialInvestment,
            interestRate,
            numberOfYears);
        cout << endl;

        /* Balance and Interest With Monthly Deposits table */
        userBank.calculateBalanceWithMonthlyDeposit(
            initialInvestment,
            monthlyDeposit,
            interestRate,
            numberOfYears);
        cout << endl;

        /* Prompt user to continue */
        string investAgain;
        cout << "Would you like to test with different values? (y/n): ";
        cin >> investAgain;

        if (investAgain == "y") {
            continue;
        }
        else {
            continueAirgeadBanking = false;
        }
    }

    return 0;
}