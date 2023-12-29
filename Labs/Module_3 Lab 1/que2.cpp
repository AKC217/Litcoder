#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int combineCandies(int target, vector<int>& candies) {
    sort(candies.begin(), candies.end());
    int steps = 0;

    while (candies[0] < target) {
        int combinedSweetness = candies[0] + 2 * candies[1];
        candies.erase(candies.begin());
        candies.erase(candies.begin());
        candies.push_back(combinedSweetness);
        sort(candies.begin(), candies.end());
        steps++;
    }

    return steps;
}

int main() {
    // Exercise-1
    int target1;
    cin >> target1;
    vector<int> candies1;
    for (int i = 0; i < 5; ++i) {
        int sweetness;
        cin >> sweetness;
        candies1.push_back(sweetness);
    }
    int result1 = combineCandies(target1, candies1);
    cout << result1 << endl;

    // Exercise-2
    int target2;
    cin >> target2;
    vector<int> candies2;
    for (int i = 0; i < 6; ++i) {
        int sweetness;
        cin >> sweetness;
        candies2.push_back(sweetness);
    }
    int result2 = combineCandies(target2, candies2);
    cout << result2 << endl;

    return 0;
}
                                                                                                                            