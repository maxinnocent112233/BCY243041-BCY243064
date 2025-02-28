#include <iostream>
#include <iomanip>
using namespace std;

double cal_taxable_income(double annual_income, double deductions)
{
    double taxable_income;
    double tax_amount = 0;
    const double bracket1 = 100000;
    const double bracket2 = 500000;
    const double rate1 = 0.2;
    const double rate2 = 0.3;
    const double rate3 = 0.5;

    // Calculating Taxable Income
    taxable_income = annual_income - deductions;


    if (taxable_income < 0) {
        taxable_income = 0;
    }

    if (taxable_income < 100000)
    {
        tax_amount = 0; // No tax payable
        cout << "No tax Payable" << endl;
    }
    else if (taxable_income <= bracket1)
    {
        tax_amount = taxable_income * rate1;
    }
    else if (taxable_income <= bracket2)
    {
        tax_amount = taxable_income * rate2;
    }
    else
    {
        tax_amount = taxable_income * rate3;
    }

    cout << fixed << setprecision(2); // Set fixed-point notation with 2 decimal places
    // cout << "Taxable Income: " << annual_income - deductions << endl;
    cout << "Taxable Income: " << taxable_income << endl;
    cout << "Deductions: " << deductions << endl;

    return tax_amount;
}

int main()
{
    cout << "_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ " << endl;
    cout << endl;
    double annual_income, deductions;
    cout << "ANNUAL INCOME " ;
    cout << endl;
    cout << "Enter your Annual Income: ";
    cin >> annual_income;

    // Validate annual income
    while (annual_income < 0) {
        cout << "Annual income cannot be negative. Please enter a valid amount: ";
        cin >> annual_income;
    }
    cout << "DEDUCTIONS";
    cout << endl;
    cout << "Enter Your Deductions (for e.g: savings, medical): ";
    cin >> deductions;

    // Validate deductions
    while (deductions < 0) {
        cout << "Deductions cannot be negative. Please enter a valid amount: ";
        cin >> deductions;
    }

    double tax_amount = cal_taxable_income(annual_income, deductions);
    cout << "Tax Amount: " << tax_amount << endl;

    return 0;
}