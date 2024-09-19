#include <iostream>
#include <string>
using namespace std;

// Function to check if the date is valid for the given month
bool isValidDate(int month, int day) {
    if (month < 1 || month > 12 || day < 1) return false;
    int days_in_month[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    if (day > days_in_month[month - 1]) return false;
    return true;
}

// Function to determine the season, temperature, and rainy days based on birthday
void getSeasonAndWeather(int month, int day) {
    string season, description, similarMonths;
    int avgTemperature, avgRainyDays;

    if ((month == 12 && day >= 22) || (month == 1) || (month == 2 && day <= 21)) {
        season = "Winter";
        description = "Cold and snowy";
        avgTemperature = -5;  // W1 average temperature
        avgRainyDays = 12;    // W1 average rainy days
        similarMonths = "W1, W2, W3";
    }
    else if ((month == 2 && day >= 22) || (month == 3 && day <= 19)) {
        season = "Winter";
        description = "Cold and snowy";
        avgTemperature = -10;  // W3 average temperature
        avgRainyDays = 8;      // W3 average rainy days
        similarMonths = "W1, W2, W3";
    }
    else if ((month == 3 && day >= 20) || (month == 4) || (month == 5 && day <= 19)) {
        season = "Spring";
        description = "Cool and blooming";
        avgTemperature = 8;  // SP2 average temperature
        avgRainyDays = 10;   // SP2 average rainy days
        similarMonths = "SP1, SP2, SP3";
    }
    else if ((month == 5 && day >= 20) || (month == 6 && day <= 20)) {
        season = "Spring";
        description = "Cool and blooming";
        avgTemperature = 15;  // SP3 average temperature
        avgRainyDays = 9;     // SP3 average rainy days
        similarMonths = "SP1, SP2, SP3";
    }
    else if ((month == 6 && day >= 21) || (month == 7) || (month == 8 && day <= 20)) {
        season = "Summer";
        description = "Hot and sunny";
        avgTemperature = 26;  // SU2 average temperature
        avgRainyDays = 8;     // SU2 average rainy days
        similarMonths = "SU1, SU2, SU3";
    }
    else if ((month == 8 && day >= 21) || (month == 9 && day <= 22)) {
        season = "Summer";
        description = "Hot and sunny";
        avgTemperature = 25;  // SU3 average temperature
        avgRainyDays = 8;     // SU3 average rainy days
        similarMonths = "SU1, SU2, SU3";
    }
    else if ((month == 9 && day >= 23) || (month == 10) || (month == 11 && day <= 22)) {
        season = "Autumn";
        description = "Cool and breezy";
        avgTemperature = 13;  // A2 average temperature
        avgRainyDays = 10;    // A2 average rainy days
        similarMonths = "A1, A2, A3";
    }
    else if ((month == 11 && day >= 23) || (month == 12 && day <= 21)) {
        season = "Autumn";
        description = "Cool and breezy";
        avgTemperature = 5;   // A3 average temperature
        avgRainyDays = 11;    // A3 average rainy days
        similarMonths = "A1, A2, A3";
    }

    // Output the results
    cout << "Season: " << season << endl;
    cout << "Weather description: " << description << endl;
    cout << "Average temperature: " << avgTemperature << "°C" << endl;
    cout << "Average number of rainy days: " << avgRainyDays << " days" << endl;
    cout << "Similar seasonal months: " << similarMonths << endl;
}

int main() {
    int month, day;

    // Get the user's birthday
    cout << "Enter your birth month (1-12): ";
    cin >> month;
    cout << "Enter your birth day: ";
    cin >> day;

    // Validate the date
    if (!isValidDate(month, day)) {
        cout << "Invalid date! Please try again." << endl;
        return 1;  // Exit the program if invalid input
    }

    // Determine and display season, temperature, and rainy days
    getSeasonAndWeather(month, day);

    return 0;
}
