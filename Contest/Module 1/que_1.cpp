#include <iostream>
#include <vector>
std::string generatePin(const std::vector<int>& numbers) {
    // Step 1: Find cumulative sum of all digits until a single digit
    int cumulativeSum = 0;
    for (int number : numbers) {
        for (char digit : std::to_string(number)) {
            cumulativeSum += digit - '0';
        }
    }
    while (cumulativeSum >= 10) {
        cumulativeSum = cumulativeSum / 10 + cumulativeSum % 10;
    }

    // Step 2: Replace odd numbers with respective lowercase alphabets
    std::string pin;
    for (int number : numbers) {
        for (char digit : std::to_string(number)) {
            if ((digit - '0') % 2 == 1) {
                pin += 'a' + digit - '1';
            } else {
                pin += digit;
            }
        }
    }

    // Ensure the PIN has exactly six characters
    pin.resize(6, 'a');

    return pin;
}

int main() {
    // Exercise-1
    std::vector<int> inputNumbers1 = {145, 875, 695, 214, 12, 1};
    std::string outputPin1 = generatePin(inputNumbers1);
    std::cout<< outputPin1 << std::endl;

    // Exercise-2
    std::vector<int> inputNumbers2 = {10, 20, 30, 40, 50, 60};
    std::string outputPin2 = generatePin(inputNumbers2);
    std::cout<< outputPin2 << std::endl;

    return 0;
}
                                                                                                                            