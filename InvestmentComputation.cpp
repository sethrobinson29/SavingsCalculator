#include "InvestmentComputation.h"


//Set Functions
void Investment::SetUserInvestment(double investment) {
	userInvestment = investment;
}
void Investment::SetUserDeposit(double deposit) {
	userDeposit = deposit;
}
void Investment::SetUserInterest(double interest) {
	userInterest = interest;
}
void Investment::SetUserYears(double years) {
	userYears = years;
}

//Get Functions
double Investment::GetUserInvestment() {
	return userInvestment;
}
double Investment::GetUserDeposit() {
	return userDeposit;
}
double Investment::GetUserInterest() {
	return userInterest;
}
double Investment::GetUserYears() {
	return userYears;
}

//Calculates interest by month, populates vectors monthlyInvestmentVals and yearlyInvestmentVals with appropriate values
void Investment::InvestmentComputation() {
	//calulate monthlyInterest
	monthlyInterest = ((monthlyTotal + userDeposit) * ((userInterest / 100) / 12));

	numMonths = userYears * 12;
	monthlyTotal = userInvestment;
	//loop for monthlyInvestmentVals
	for (i = 0; i < numMonths; ++i) {
		monthlyInterest = ((monthlyTotal + userDeposit) * ((userInterest / 100) / 12));
		monthlyTotal += userDeposit + monthlyInterest;
		monthlyInvestmentVals.push_back(monthlyTotal);
	}

	//loop for yearlyInvestmentVals
	i = 11; //first element is the total balance of year1
	while (i < numMonths) {
		for (j = 0; j < userYears; ++j) {
			yearlyInvestmentVals.push_back(monthlyInvestmentVals.at(i));
			i += 12;
			if (i > numMonths) {
				break;
			}
	   }
	}

}

//prints yearly investment vector
void Investment::PrintYearlyReturn() {
	cout << fixed << setprecision(2);

	//prints first row in table for yearly investment vector
	yearlyTotal = yearlyInvestmentVals.at(0) - ((userDeposit * 12) + userInvestment);

	cout << setw(3) << 1 << setw(19) << yearlyInvestmentVals.at(0) << setw(21) <<
		yearlyTotal << endl;

	//prints rest of table for yearly investment vector
	for (i = 1; i < yearlyInvestmentVals.size(); ++i) {
		yearlyTotal = (yearlyInvestmentVals.at(i) - yearlyInvestmentVals.at(i - 1)) - (userDeposit * 12);

		cout << setw(3) << i + 1 << setw(19) << yearlyInvestmentVals.at(i) << setw(21) <<
			yearlyTotal << endl;
	}
}

//prints monthly investment vector
void  Investment::PrintMonthlyReturn() {
	cout << setprecision(2) << fixed;

	//prints first row in table for monthly investment vector
	monthlyTotal = monthlyInvestmentVals.at(0) - userDeposit - 1;
	cout << setw(3) <<  1 << setw(19) << monthlyInvestmentVals.at(0) << setw(21) <<
		monthlyTotal << endl;
	
	//prints rest of table for monthly investment vector
	for (i = 1; i < 12; ++i) {
		monthlyTotal = (monthlyInvestmentVals.at(i) - monthlyInvestmentVals.at(i - 1)) - userDeposit;
		cout << setw(3) << i + 1 << setw(19) << monthlyInvestmentVals.at(i) << setw(21) <<
			monthlyTotal << endl;
	}
}