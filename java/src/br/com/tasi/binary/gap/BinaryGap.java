
package br.com.tasi.binary.gap;

import java.util.ArrayList;
import java.util.List;

public class BinaryGap {

    public static void main(String[] args) {
        List<Integer> result = new ArrayList<>();
        BinaryGap b = new BinaryGap();
        // Test cases
        int[] numbersToTest = {9, 529, 20, 15, 32, 1041, 32, 647, 483, 147, 1, 5, 101_2, 2147483647, 16, 11, 42, 20};
        for (int value : numbersToTest) {
            System.out.println("=================================================");
            System.out.println(String.format("Testing number: %d", value));
            System.out.println(String.format("Longest gap: %d", b.solution(value)));
            System.out.println("=================================================\n");
        }
    }

    /**
     * Returns the longest binary gap in the given number.
     * @param number Given number.
     * @return the longest binary gap in the given number. Zero if there's no gap.
     */
    public int solution(int number) {
        int result = 0;
        String binary = Integer.toBinaryString(number);
        boolean initGap = false;
        int counter = 1;
        for (char binChar : binary.toCharArray()) {
            if (binChar == '1') {
                if (initGap && counter > result) {
                    result = counter;
                }
                counter = 1;
                initGap = false;
            } else if (initGap) {
                counter++;
            } else if (binChar == '0') {
                initGap = true;
            }
        }
        return result;
    }

    /**
     * Finds the longgest zero gap inside the binary number using bitwise operations.
     * @param number given number to evaluate the longgest gap.
     * @return Returns the longgest zero gap inside the binary number.
     */
    int longgestGapBitwise(int number) {
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
        boolean foundOne = false;
        // Creates a bit discolator to check each bit from the parameter value
        // And only stopes when the comparator number has the same value as the parameter
        for (int disloc = 0; compNum != number; disloc++) {
            // Creates an integer with only one bit activated
            int bitDisloc = 1 << disloc;
            int valueToComp = number & bitDisloc;
            // Makes a AND wise comparator between the two numbers to check
            // if the bit in the same position as disloc is activated
            if (valueToComp == 1) {
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
            compNum |= valueToComp;
        }
        return result;
    }
}
