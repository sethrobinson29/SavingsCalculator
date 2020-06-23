#pragma once
#ifndef INVESTMENT_COMPUTATION_H_
#define INVESTMENT_COMPUTATION_H_

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <string>
#include <vector>
using namespace std;

class Investment {
public:
	//default constructor
	Investment() {
		userInvestment = 0;
		userDeposit = 0;
		userInterest = 0;
		userYears = 0;
		
	}
	//constructor
	Investment(double investment, double deposit, double interest, double years) {
		userInvestment = investment;
		userDeposit = deposit;
		userInterest = interest;
		userYears = years;
		
	}
	//sets individual members
	void SetUserInvestment(double investment);
	void SetUserDeposit(double userDeposit);
	void SetUserInterest(double interest);
	void SetUserYears(double years);
	//gets individual members
	double GetUserInvestment();
	double GetUserDeposit();
	double GetUserInterest();
	double GetUserYears();
	void InvestmentComputation();
	void PrintYearlyReturn();
	void PrintMonthlyReturn();
private:
	//variables
	unsigned int i;
	unsigned int j;
	//variables for computation
	double numMonths;
	double monthlyInterest;
	double monthlyTotal;
	double yearlyTotal;
	//variables in constructor
	double userInvestment;
	double userDeposit;
	double userInterest;
	double userYears;
	//for displaying balance and interest earned
	vector<double> monthlyInvestmentVals;
	vector<double> yearlyInvestmentVals;
};












#endif //INVESTMENT_COMPUTATION_H_
