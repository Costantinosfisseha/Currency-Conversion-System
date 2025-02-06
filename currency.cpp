#include <iostream>
#include <iomanip> 

using namespace std;

//conversion rates (initialized as constants)
const double USD_TO_EUR = 0.85;
const double USD_TO_GBP = 0.75;
const double USD_TO_JPY = 110.00;
const double EUR_TO_USD = 1.18;
const double GBP_TO_USD = 1.33;
const double JPY_TO_USD = 0.0091;

//function to convert currency
double convertCurrency(double amount, double rate) {
    return amount * rate;
}

//function to modify conversion rates temporarily
void applyPromotionalRate(double& rate, double newRate) {
    rate = newRate;
}

int main() {
    double amount;
    int choiceFrom, choiceTo;
    
    cout << "Currency Conversion System" << endl;
    cout << "Available currencies: \n1. USD\n2. EUR\n3. GBP\n4. JPY" << endl;
    
    cout << "Enter the amount: ";
    cin >> amount;
    
    cout << "Select the currency to convert from (1-4): ";
    cin >> choiceFrom;
    
    cout << "Select the currency to convert to (1-4): ";
    cin >> choiceTo;
    
    double rate = 1.0;
    //rate would change based on what currency you trying to convert 
    if (choiceFrom == 1 && choiceTo == 2) rate = USD_TO_EUR;
    else if (choiceFrom == 1 && choiceTo == 3) rate = USD_TO_GBP;
    else if (choiceFrom == 1 && choiceTo == 4) rate = USD_TO_JPY;
    else if (choiceFrom == 2 && choiceTo == 1) rate = EUR_TO_USD;
    else if (choiceFrom == 3 && choiceTo == 1) rate = GBP_TO_USD;
    else if (choiceFrom == 4 && choiceTo == 1) rate = JPY_TO_USD;
    else {
        cout << "Invalid currency selection!" << endl;
        return 1;
    }
    
    double convertedAmount = convertCurrency(amount, rate);
    cout << fixed << setprecision(2);
    cout << "Converted Amount: " << convertedAmount << endl;
    
    // simulate promotional rate change
    cout << "Applying promotional rate " << endl;
    double promotionalRate = rate * 1.05; //increase by 5%
    applyPromotionalRate(rate, promotionalRate);
    convertedAmount = convertCurrency(amount, rate);
    cout << "New Converted Amount 'with promo rate': " << convertedAmount << endl;
    
    return 0;
}