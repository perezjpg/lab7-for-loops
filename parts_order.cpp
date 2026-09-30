/*
 * Course: COEN 2210 - Introduction to Programming
 * Name: Johnatanel Perez Lopez
 * Lab: 7 - Loops II
 * Description: [What this specific program does]
 * Due Date: September 30, 2026
 */
#include <iostream>                                      // Provides cin, cout, and endl
#include <iomanip>                                       // Provides fixed and setprecision
using namespace std;                                     // Allows standard-library names without the std:: prefix

int main() {                                             // Starts the program
    int requestCount;                                    // Stores the known number of part requests
    int partChoice;                                      // Stores one menu selection
    int quantity;                                        // Stores the requested quantity for one part
    int validLineCount = 0;                              // Counts requests that have a valid part and quantity
    double unitPrice;                                    // Stores the price selected by the switch
    double lineCost;                                     // Stores the cost of one valid request
    double orderTotal = 0.0;                             // Accumulates all valid line costs
    bool isValidPartChoice;                              // Tracks whether the switch selected a real part

    cout << "Enter number of part requests from 1 to 5: "; // Prompts for the iteration count
    cin >> requestCount;                                 // Reads the first request-count candidate

    while (requestCount < 1 || requestCount > 5) {
        cout << "Invalid request count. Try again: ";
        cin >> requestCount;
    }

    for (int request = 1; request <= requestCount; request++) {
        isValidPartChoice = true;

        cout << "\nRequest " << request << endl;
        cout << "1. Cable set" << endl;
        cout << "2. Fuse Pack" << endl;
        cout << "3. Connector kit" << endl;
        cout << "Enter part choice: ";
        cin >> partChoice;

        while (partChoice < 1 || partChoice > 3) {
            cout << "Invalid part choice. Try again: ";
            cin >> partChoice;
        }

        switch (partChoice) {
            case 1:
                unitPrice = 3.25;
                cout << "Selected: Cable set" << endl;
                break;
            case 2:
                unitPrice = 4.50;
                cout << "Selected: Fuse Pack" << endl;
                break;
            case 3:
                unitPrice = 1.75;
                cout << "Selected: Connector Kit" << endl;
                break;
            default:
                isValidPartChoice = false;
                break;
        }

        if (isValidPartChoice) {
            cout << "Enter quantity from 1 to 5: ";
            cin >> quantity;

            if (quantity >= 1 && quantity <= 5) {
                lineCost = unitPrice * quantity;
                orderTotal += lineCost;
                validLineCount++;
                cout << fixed << setprecision(2);
                cout << "Line cost: $" << lineCost << endl;
            } else {
                cout << "Invalid quantity. Request skipped." << endl;
            }
        }
    }

    cout << fixed << setprecision(2);
    cout << "\nValid lines processed: " << validLineCount << endl;
    cout << "Order total: $" << orderTotal << endl;

    return 0;
}
/*
 * Test analysis:
 * 1. orderTotal starts at 0.0 so the valid line costs can be added to zero.
 * 2. An invalid part choice asks again so the user enters a valid choice.
 * 3. isValidPartChoice is reset so each request is checked independently.
 * 4. An invalid quantity is skipped, so it is not counted as a valid line.
 */