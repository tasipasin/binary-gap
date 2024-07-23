#include <string>
#include <bitset>
#include <iostream>
#include <vector>

using namespace std;

/**
 * Finds the longgest zero gap inside the binary number using their binary string.
 * @param N given number to evaluate the longgest gap.
 * @return Returns the longgest zero gap inside the binary number.
 */
int longgestGap(int N) {
    int result = 0;
    // Gets the current integer as a binary string
    string binaryString = bitset<32>(N).to_string();
    int counter = 0;
    // The bitset function returns all the 32 bits, even if the number doesn't
    // actually uses all of them, so to save time and processing, the first one
    // is found to start from there
    size_t begin = binaryString.find("1");
    // Runs through the rest of the string
    for (size_t pos = begin; pos < binaryString.size(); pos++) {
        // Gets the char in the position
        char binChar = binaryString.at(pos);
        // If a one is found, update the longgest gap, if has found one
        // and reset temporary gap counter
        if (binChar == '1') {
            if (counter > result) {
                result = counter;
            }
            counter = 0;
        }
        else {
            counter++;
        }
    }
    return result;
}

/**
 * Finds the longgest zero gap inside the binary number using bitwise operations.
 * @param N given number to evaluate the longgest gap.
 * @return Returns the longgest zero gap inside the binary number.
 */
int longgestGapBitwise(int N) {
    // The longgest Gap to return
    int result = 0;

    /** Temp variables */
    // Temp gap counter
    int counter = 0;
    // Temp comparator number (this number must have the same value
    // of the parameter sometimes)
    int compNum = 0;
    // Indicates the first one has been found
    // A sequence of zeros cannot be counted as gap if isn't between ones
    bool foundOne = false;
    // Creates a bit discolator to check each bit from the parameter value
    // And only stopes when the comparator number has the same value as the parameter
    for (int disloc = 0; compNum != N; disloc++) {
        // Creates an integer with only one bit activated
        int bitDisloc = 1 << disloc;
        // Makes a AND wise comparator between the two numbers to check
        // if the bit in the same position as disloc is activated
        if (N & bitDisloc) {
            // Indicates to the algorithm that the first one is found
            // So the next zero can be count to gap
            foundOne = true;
            // Checks if the current gap is longger than the previous one
            if (counter > result) {
                result = counter;
            }
            // Restarts temp gap counter
            counter = 0;
        } // Increments temp counter when a zero is found after
        // the first one has already been found
        else if (foundOne) {
            counter++;
        }
        // Activates the bit on the comparator number
        compNum |= (N & bitDisloc);
    }
    return result;
}

int main() {
    vector<int> testCases{ 9, 529, 20, 15, 32, 1041, 32, 647, 483, 147, 1, 5, 1012, 2147483647, 16, 11, 42, 20 };
    for (int test : testCases) {
        cout << "=================================================" << endl;
        cout << "Testing number: " << test << endl;
        cout << "Longest gap: " << longgestGap(test) << endl;
        cout << "Longest gap (bitwise): " << longgestGapBitwise(test) << endl;
        cout << "=================================================" << endl << endl;
    }
}
