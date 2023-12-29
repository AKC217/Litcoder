#include <iostream>
#include <vector>

int numberOfPeopleAware(int n, int delay, int forget) {
    std::vector<int> dp(n + 1, 0);
    dp[0] = 1;

    for (int i = 1; i <= n; ++i) {
        dp[i] = dp[i - 1];
        if (i >= delay) {
            dp[i] += dp[i - delay];
        }
        if (i > forget) {
            dp[i] -= dp[i - forget - 1];
        }
    }

    return dp[n] - dp[std::max(0, n - forget)];
}

int main() {
    

    // Exercise-1
    int n1 = 4;
    int delay1 = 1;
    int forget1 = 3;
    int result1 = numberOfPeopleAware(n1, delay1, forget1);
    std::cout <<result1 << std::endl;

    // Exercise-2
    int n2 = 3;
    int delay2 = 2;
    int forget2 = 3;
    int result2 = numberOfPeopleAware(n2, delay2, forget2);
    std::cout << result2 << std::endl;

    return 0;
}
                                                                                                                            