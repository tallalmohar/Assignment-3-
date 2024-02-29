#include <iomanip>
#include <ios>
#include <iostream>
#include <string>

using namespace std;

const double tempChangePer_1PPM = 0.0091; // change in temp per 1 PPM CO2
const double ppmCo2_2023 = 412.50;
const double avrgTempVan_2023 = 22.00;
const int startYear = 2023;

string commentFunc(double tempDifference) {
  double change = tempDifference;
  if (change < -1) {
    return "Getting cold!";
  } else if (change > -1 && change <= -0.5) {
    return "Getting cooler!";
  } else if (change >= -0.5 && change < 0.5) {
    return "NO MESSAGE!";
  } else if (change >= 0.5 && change < 1.0) {
    return "Getting warmer";
  } else if (change > 1.0 && change <= 1.5) {
    return "That's the dream!";
  } else if (change > 1.5 && change <= 2.0) {
    return "Think we can hold it here?";
  } else if (change > 2.0 && change <= 5.0) {
    return "UH OH! It's HOT!";
  }
  return "";
}

void printTable(double yearsToPrint, double c02Change_yearly) {
  int returnedYearPerLoop = startYear;
  double returnedC02PerLoop = ppmCo2_2023;
  double tempChangePerLoop = 0.00;
  double tempVanPerLoop = avrgTempVan_2023;

  for (int i = 0; i <= yearsToPrint; i++) {
    if (i == yearsToPrint) {
      break;
    }
    cout << fixed << setprecision(2);
    cout << returnedYearPerLoop++ << setw(12) << returnedC02PerLoop << "ppm"
         << setw(13) << showpos << tempChangePerLoop << "'C" << noshowpos
         << setw(13) << tempVanPerLoop << "'C";
    cout << "        " << commentFunc(tempChangePerLoop) << endl;
    returnedC02PerLoop += c02Change_yearly;
    tempChangePerLoop += (c02Change_yearly * tempChangePer_1PPM);
    tempVanPerLoop += tempChangePerLoop;
  }
}

int main() {
  cout << "BOGUS CO2 to Temperature Change Table Generator\n"
       << "-----------------------------------------------" << endl;
  double yearlyChange_CO2 = 0;
  double numOfYears = 0;

  cout << "Enter the yearly change in CO2 [ppm]: ";
  cin >> yearlyChange_CO2;
  cout << "Enter the number of years to print: ";
  cin >> numOfYears;

  // FORLOOPS/LOGIC to print the table
  cout << "Year" << setw(15) << "CO2ppm" << setw(15) << "Temp Chng'C"
       << setw(15) << "Van Summer'C" << setw(15) << "Comment" << endl;

  printTable(numOfYears, yearlyChange_CO2); // prints values of the table

  return 0;
}
