/** File: project1_Upadhyay_spu0004.cpp
  * Author: Shanti Upadhyay
  * Auburn ID: 903998817
  * IDE: jGrasp, compiled with g++
  **Important!: Unable to upload to AU Server. Asked TA Tian Liu for solutions but
  **            they did not work. 
  * References:
  * - Project1_hints.pdf from Canvas
  * - https://jesushilarioh.com/error-checking-input-validation-in-c-plus-plus-double/ to
  *   flag invalid user input for "loan" and "interestRate" - while (!(cin >> loan)),
  *   cin.clear(), cin.ignore(123, '/n')
  * - w3.cs to create a C++ environment for jGrasp 
  * Note: Instead of doing "Compile" then "Run", 
  *       need to "Compile and Link" then "Run"
  **/
#include <iostream>
using namespace std;

int main() {

    // currency formatting
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);
    
    // user input begins
    cout << "\nLoan Amount: ";

    double loan = 0; 
    while (loan < 0 || (!(cin >> loan))) {   // if input is neg. or not a double
        cout << "\nError. Please enter a positive number: ";
        cin.clear(); // clear input stream
        cin.ignore(123, '\n'); // ignore previous input
    }

    cout << "Interest Rate (% per year): ";
    
    double interestRate = 0; 
    while (interestRate < 0 || (!(cin >> interestRate))) {  // if input is neg. or not a double
        cout << "\nError. Please enter a positive number: ";
        cin.clear(); // clear input stream
        cin.ignore(123, '\n'); // ignore previous input
    }
    
    // proper rates for calculations
    double interestRateC = 0;
    interestRate /= 12;
    interestRateC = interestRate / 100;
    
    // user inputs monthly payments
    double monthlyPay = 0;
    cout << "Monthly Payments: ";
    cin >> monthlyPay;

    while (monthlyPay <= loan * interestRateC) {
        cout << "\nError. Please ensure you entered the correct values: ";
        cin >> monthlyPay;
    }


    // amortization table
    cout << "*****************************************************************\n"
    << "\tAmortization Table\n"
    << "**********************************************************************\n"
    << "Month\tBalance\t\tPayment\tRate\tInterest\tPrincipal\n";
    
    // variables used to create table
    int currentMonth = 0;
    double principalAmt = 0;
    double interestTotal = 0;
    double monthlyInterest = 0;
    
    // loop to fill table
    while (loan > 0) {
    
        if (currentMonth == 0) {
         cout << currentMonth++ 
         << "\t$" 
         << loan;
        
        if (loan < 1000) cout << "\t"; // Formatting MAGIC
         cout << "\t" << "N/A\tN/A\tN/A\t\tN/A\n";
        }
        
        else {
               monthlyInterest = loan * interestRateC;
               interestTotal += monthlyInterest;
               principalAmt = monthlyPay - monthlyInterest;
               
            if (loan > monthlyPay) {
               loan -= principalAmt;
            } 
            
            else {
                principalAmt = loan;
                monthlyPay = loan + monthlyInterest;
                loan = 0;
            }


            if (loan < 1000) {
                cout << currentMonth++ 
                << "\t$" 
                << loan 
                << "\t\t" 
                << monthlyPay 
                << "\t" 
                << interestRate 
                << "\t" 
                << monthlyInterest 
                << "\t\t" 
                << principalAmt 
                << "\n";
            } 
            
            else {
                cout << currentMonth++ 
                << "\t$" 
                << loan 
                << "\t" 
                << monthlyPay 
                << "\t" 
                << interestRate 
                << "\t" 
                << monthlyInterest 
                << "\t\t" 
                << principalAmt << "\n";             
            }
        }
    }
    cout << "****************************************************************\n";
    cout << "\nIt takes " << --currentMonth << " months to pay off "
    << "the loan.\n"
    << "Total interest paid is: $" << interestTotal;
    cout << endl << endl;
    return 0;
}