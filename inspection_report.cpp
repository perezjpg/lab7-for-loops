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
    int deviceCount;                                     // Stores the known number of devices in the batch
    int passingDeviceCount = 0;                          // Counts devices with a passing quality score
    double qualityScore;                                 // Stores one device score per iteration
    double totalScore = 0.0;                             // Accumulates all quality scores

    cout << "Enter number of devices from 1 to 10: ";  // Prompts for the batch size
    cin >> deviceCount;                                  // Reads the first batch-size candidate

    while (deviceCount < 1 || deviceCount > 10) {        // Repeats while the batch size is outside the allowed range
        cout << "Invalid device count. Try again: ";    // Explains why another batch size is required
        cin >> deviceCount;                              // Reads a replacement batch size
    }                                                     // Ends after a valid batch size is entered

    for (int device = 1; device <= deviceCount; device++) { // Repeats once for each requested device
        cout << "Enter quality score for device " << device << ": "; // Identifies the current device in the prompt
        cin >> qualityScore;                              // Reads one quality score for this iteration
        totalScore += qualityScore;                       // Adds this score to the running total

        if (qualityScore >= 70.0) {                       // Checks whether the score is passing
            passingDeviceCount++;                         // Counts one passing device
            cout << "Device passes inspection." << endl;  // Reports the passing result
        } else {                                          // Handles a failing score
            cout << "Device requires review." << endl;   // Reports the failing result
        }                                                 // Ends the selection structure
    }                                                     // Ends the count-controlled loop
        double averageScore = totalScore / deviceCount; // Calculates the average after all scores are accumulated

    cout << fixed << setprecision(2);                    // Formats displayed decimal values with two places
    cout << "Total quality score: " << totalScore << endl; // Displays the accumulated quality score total
    cout << "Average quality score: " << averageScore << endl; // Displays the calculated average
    cout << "Passing devices: " << passingDeviceCount << endl; // Displays the conditional counter

    return 0;                                            // Ends the program successfully
} 
/*
 * Analysis:
 * 1. The totalScore starts at 0.0 because it is initialized to zero before any scores are added. This ensures that the accumulation of scores begins from a neutral value, allowing for accurate calculation of the total and average scores.
 * 2. The passingDeviceCount increments when a device has a quality score of 70.0 or higher, but not for a score of 69.0, because the condition checks for scores greater than or equal to 70.0.
 * 3. The averageScore is calculated after the for loop to ensure that all quality scores have been accumulated and the total is available for the calculation.
 */                                                       