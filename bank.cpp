#include <iostream>
using namespace std;

int main(const int argc, const char* argv[]) {
// Program to calculate savings, monthly payments and percent interest rates
    float D = atof(argv[1]);
    float P = atof(argv[2]);
    float i = atof(argv[3]);

    cout <<"Desired Savings: $" << D << endl;
    cout <<"Monthly Payment: $" << P << endl;
    cout <<"Percent Interest Rate: " << i << "%" << endl;

    int months = 0;
    float amount;

    for (amount = 0; amount < D; months++){
        amount = amount + (amount * (i/12/100)) + P;
    }

   // int years = months / 12;
    //months = months % 12;

    cout <<"Time to reach desired savings: " << months/12 << " years and " << months%12 << " months.";


}
