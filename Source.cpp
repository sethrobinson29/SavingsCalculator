#include "InvestmentComputation.h"
#include <iostream>
#include <iomanip>

using namespace std;


int main(){
    char userKey = 'a'; //to progress Program
    //variables to capture user input for function
    double userInitialInvestment;
    double userMonthlyDeposit;
    double userAnnualInterest;
    double userNumYears;

    
    while (userKey != 'x') {
        //initial user entries
        cout << "************************************" << endl;
        cout << "********** Data Input **************" << endl;
        cout << "Initial Investment Amount: " << endl;
        cin >> userInitialInvestment;
        cout << "Monthly Deposit: " << endl;
        cin >> userMonthlyDeposit;
        cout << "Annual Interest: %" << endl;
        cin >> userAnnualInterest;
        cout << "Number of years: " << endl;
        cin >> userNumYears;

        //creates Investment object 
        Investment userInvestment(userInitialInvestment, userMonthlyDeposit, userAnnualInterest, userNumYears);

        //displays balance and interest with additional deposits
        cout << "*****************************************************" << endl;
        cout << "Balance and Interest With Additional Monthly Payments" << endl;
        cout << "*****************************************************" << endl;
        cout << "*****************************************************" << endl;
        cout << "Year    Year End Balance     Year End Earned Interest" << endl;
        cout << "*****************************************************" << endl;
        userInvestment.InvestmentComputation();
        userInvestment.PrintYearlyReturn();

        //creates Investment object with no deposits
        Investment userSavings(userInitialInvestment, 0.0, userAnnualInterest, userNumYears);

        //displays balance and interest without additional deposits
        cout << endl;
        cout << endl;
        cout << "*****************************************************" << endl;
        cout << "Balance and Interest Without Additional Monthly Payments" << endl;
        cout << "*****************************************************" << endl;
        cout << "*****************************************************" << endl;
        cout << "Year    Year End Balance     Year End Earned Interest" << endl;
        cout << "*****************************************************" << endl;
        userSavings.InvestmentComputation();
        userSavings.PrintYearlyReturn();

        cout << endl;
        cout << endl;
        cout << "Press \"M\" to display monthly statement..." << endl;
        cout << "Press \"X\" to end, press any other key to continue..." << endl;
        cin >> userKey;  

        //displays monthly balance and interest
        if (userKey == 'm' || userKey == 'M') {
            cout << "*****************************************************" << endl;
            cout << "Monthly Balance with Deposits (12 months)" << endl;
            cout << "*****************************************************" << endl;
            userInvestment.PrintMonthlyReturn();

            cout << "Press \"X\" to end, press any other key to continue..." << endl;
            cin >> userKey;

        }
        else if (userKey == 'x' || userKey == 'X') {
            break;
        }
        else {
            continue;
        }
    }

	return 0;
}





