#include <iostream>
#include <vector>
int maxAlternatingSum(const std::vector<int>& nums) {
    int n = nums.size();

    // Initialize variables to store the maximum alternating sum at even and odd indices
    int maxEven = 0;
    int maxOdd = 0;

    for (int num : nums) {
        // Calculate the new maximum alternating sum at even and odd indices
        int newMaxEven = std::max(maxOdd + num, maxEven);
        int newMaxOdd = std::max(maxEven - num, maxOdd);

        // Update the maximum alternating sums
        maxEven = newMaxEven;
        maxOdd = newMaxOdd;
    }

    // Return the maximum alternating sum
    return std::max(maxEven, maxOdd);
}

int main() {
    // Exercise-1
    std::vector<int> inputNums1 = {4, 6, 5, 3};
    int output1 = maxAlternatingSum(inputNums1);
    std::cout<< output1 << std::endl;

    // Exercise-2
    std::vector<int> inputNums2 = {4, 6, 5, 3, 4, 9, 5};
    int output2 = maxAlternatingSum(inputNums2);
    std::cout<< output2 << std::endl;

    return 0;
}
                                                                                                                            