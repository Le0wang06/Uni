#include <iostream>
#include <string>
using namespace std;


bool isValidDate(int month, int day) {
    if (month < 1 || month > 12 || day < 1) return false;
    int days_in_month[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    if (day > days_in_month[month - 1]) return false;
    return true;
}


void getSeasonAndWeather(int month, int day) {
    string season, description, similarMonths;
    int avgTemperature, avgRainyDays;

    if ((month == 12 && day >= 22) || (month == 1) || (month == 2 && day <= 21)) {
        season = "Winter";
        description = "Cold and snowy";
        avgTemperature = -5;  
        avgRainyDays = 12;    
        similarMonths = "W1, W2, W3";
    }
    else if ((month == 2 && day >= 22) || (month == 3 && day <= 19)) {
        season = "Winter";
        description = "Cold and snowy";
        avgTemperature = -10;  
        avgRainyDays = 8;     
        similarMonths = "W1, W2, W3";
    }
    else if ((month == 3 && day >= 20) || (month == 4) || (month == 5 && day <= 19)) {
        season = "Spring";
        description = "Cool and blooming";
        avgTemperature = 8; 
        avgRainyDays = 10;  
        similarMonths = "SP1, SP2, SP3";
    }
    else if ((month == 5 && day >= 20) || (month == 6 && day <= 20)) {
        season = "Spring";
        description = "Cool and blooming";
        avgTemperature = 15; 
        avgRainyDays = 9;     
        similarMonths = "SP1, SP2, SP3";
    }
    else if ((month == 6 && day >= 21) || (month == 7) || (month == 8 && day <= 20)) {
        season = "Summer";
        description = "Hot and sunny";
        avgTemperature = 26;  
        avgRainyDays = 8;     
        similarMonths = "SU1, SU2, SU3";
    }
    else if ((month == 8 && day >= 21) || (month == 9 && day <= 22)) {
        season = "Summer";
        description = "Hot and sunny";
        avgTemperature = 25; 
        avgRainyDays = 8;   
        similarMonths = "SU1, SU2, SU3";
    }
    else if ((month == 9 && day >= 23) || (month == 10) || (month == 11 && day <= 22)) {
        season = "Autumn";
        description = "Cool and breezy";
        avgTemperature = 13;
        avgRainyDays = 10;   
        similarMonths = "A1, A2, A3";
    }
    else if ((month == 11 && day >= 23) || (month == 12 && day <= 21)) {
        season = "Autumn";
        description = "Cool and breezy";
        avgTemperature = 5;   
        avgRainyDays = 11;    
        similarMonths = "A1, A2, A3";
    }

    cout << "Season: " << season << endl;
    cout << "Weather description: " << description << endl;
    cout << "Average temperature: " << avgTemperature << "°C" << endl;
    cout << "Average number of rainy days: " << avgRainyDays << " days" << endl;
    cout << "Similar seasonal months: " << similarMonths << endl;
}

int main() {
    int month, day;

    // inputs:
    
    cout << "Enter your birth month (1-12): ";
    cin >> month;
    cout << "Enter your birth day: ";
    cin >> day;

    if (!isValidDate(month, day)) {
        cout << "Invalid date! Please try again." << endl;
        return 1;  
    }

    getSeasonAndWeather(month, day);

    return 0;
}
