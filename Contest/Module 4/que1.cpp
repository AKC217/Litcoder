#include <iostream>
#include <vector>
#include <algorithm>

struct Job {
    char name;
    int deadline;
    int profit;

    Job(char n, int d, int p) : name(n), deadline(d), profit(p) {}

    bool operator<(const Job& other) const {
        return profit > other.profit;
    }
};

std::vector<char> jobSequencing(int n, const std::vector<char>& names, const std::vector<int>& deadlines, const std::vector<int>& profits) {
    std::vector<Job> jobs;
    for (int i = 0; i < n; ++i) {
        jobs.emplace_back(names[i], deadlines[i], profits[i]);
    }

    std::sort(jobs.begin(), jobs.end());

    std::vector<bool> slot(n, false);
    std::vector<char> result;

    for (int i = 0; i < n; ++i) {
        for (int j = std::min(n, jobs[i].deadline) - 1; j >= 0; --j) {
            if (!slot[j]) {
                slot[j] = true;
                result.push_back(jobs[i].name);
                break;
            }
        }
    }

    return result;
}

int main() {
    // Exercise-1
    int n1 = 5;
    std::vector<char> names1 = {'a', 'b', 'c', 'd', 'e'};
    std::vector<int> deadlines1 = {2, 1, 2, 1, 3};
    std::vector<int> profits1 = {100, 19, 27, 25, 15};

    std::vector<char> result1 = jobSequencing(n1, names1, deadlines1, profits1);

    std::cout << "";
    for (char job : result1) {
        std::cout << job << " ";
    }
    std::cout << std::endl;

    // Exercise-2
    int n2 = 5;
    std::vector<char> names2 = {'p', 'q', 'r', 's', 't'};
    std::vector<int> deadlines2 = {2, 1, 3, 1, 3};
    std::vector<int> profits2 = {99, 190, 27, 25, 15};

    std::vector<char> result2 = jobSequencing(n2, names2, deadlines2, profits2);

    std::cout << "";
    for (char job : result2) {
        std::cout << job << " ";
    }
    std::cout << std::endl;

    return 0;
}
                                                                                                                            