#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <limits>

using namespace std;

double discount, discountedPrice;
int ticketPrice, totalPrice, location, numPeople, age;
vector<int> groupAge;

int main() {
    // Map of fare matrix
    map<int, int> destination_map;
    destination_map[1] = 300;    // Mohali
    destination_map[2] = 500;    // Chandigarh
    destination_map[3] = 1000;    // Delhi
    destination_map[4] = 150;    // Minimum Distance

    // Map of destination names
    map<int, string> location_map;
    location_map[1] = "Mohali";
    location_map[2] = "Chandigarh";
    location_map[3] = "Delhi";
    location_map[4] = "Minimum Distance";

    cout << "WELCOME TO NORTH BUS STATION" << endl;
    cout << "-----------------------------" << endl;

    string destination[]{"Mohali", "Chandigarh", "Delhi", "Standard Fare (Minimum Distance)"};

    // Prints destination array
    for (int i = 0; i < 4; ++i) {
        cout << i + 1 << " - " << destination[i] << " ---> " << destination_map[i + 1] << "/-" << endl;
    }

    cout << "Select destination: ";

    // Checks if input is in the range of 1-4
    while (!(cin >> location) || (location < 1 || location > 4)) {
        cout << "Invalid Input!" << endl <<
             "Please enter a number between 1 and 4: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    cout << "Enter number of people: ";
    // Input validation, numPeople should be integer
    while (!(cin >> numPeople) || (numPeople < 1 || numPeople > 20)) {
        cout << "Invalid input!" << endl <<
             "Enter a number between 1 and 20: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    cout << "Enter age of each person:";

    // Input age of people depending on the number of participants
    for (int i = 0; i < numPeople; ++i) {
        while (!(cin >> age) || (age < 1 || age > 100)) {
            cout << "Invalid Input!" << endl <<
                 "Please enter a valid age between 1 and 100: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        groupAge.push_back(age);
    }

    // Sorts age list to get the youngest person
    sort(groupAge.begin(), groupAge.end());

    // Prints sorted list
    cout << "Sorted age list is [ ";
    for (const auto& a : groupAge) {
        cout << a << " ";
    }
    cout << "]" << endl;

    cout << "Number of people: " << numPeople << endl;
    cout << endl;

    if (numPeople >= 5) {
        // Executes discount computation, youngest age basis for discount percentage
        cout << "You are eligible for a discounted price!" << endl << endl;

        // Gets the age of the youngest person to be used as a discount percentage
        discount = 1.0 - (groupAge[0] / 100.0);

        discountedPrice = (numPeople * destination_map[location]) * discount;

        cout << "Individual ticket cost: INR " << discountedPrice / numPeople << endl;
        cout << "Total discounted price is equal to INR " << discountedPrice << endl;
    } else {
        totalPrice = numPeople * destination_map[location];
        cout << "You need to be a group of five (5) or more to avail the discount." << endl << endl;
        cout << "Ticket Summary:" << endl;
        cout << "--------------------------------" << endl;
        cout << "From: Main Terminal" << endl;
        cout << "To: " << location_map[location] << endl;
        cout << "Number of Passengers: " << numPeople << endl;
        cout << "Cost per Ticket: INR " << totalPrice / numPeople << endl;
        cout << "Total Cost (Standard Pricing): INR " << totalPrice << endl;
        cout << "--------------------------------" << endl;
    }

    cout << endl;
    cout << "THANK YOU FOR RIDING WITH NORTH BUS CORP" << endl;

    return 0;
}
