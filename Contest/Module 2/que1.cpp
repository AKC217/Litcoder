#include <iostream>
#include <unordered_map>
#include <vector>

std::vector<int> findCandies(int money, const std::vector<int>& prices) {
    std::unordered_map<int, int> priceMap;

    for (int i = 0; i < prices.size(); ++i) {
        int complement = money - prices[i];
        if (priceMap.find(complement) != priceMap.end()) {
            return {priceMap[complement] + 1, i + 1};
        }
        priceMap[prices[i]] = i;
    }

    return {};
}

int main() {
    // Exercise-1
    int money1 = 10;
    std::vector<int> prices1 = {2, 3, 4, 5, 5};
    std::vector<int> output1 = findCandies(money1, prices1);
    std::cout << "";
    for (int val : output1) {
        std::cout << " " << val;
    }
    std::cout << std::endl;

    // Exercise-2
    int money2 = 8;
    std::vector<int> prices2 = {1, 4, 7, 6, 8};
    std::vector<int> output2 = findCandies(money2, prices2);
    std::cout << "";
    for (int val : output2) {
        std::cout << " " << val;
    }
    std::cout << std::endl;

    return 0;
}
                                                                                                                            