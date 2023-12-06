#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void helper(vector<int>& set, int target, int index, int currentSum, vector<int>& possibleAns) {
    if (currentSum == target) {
        for (int num : possibleAns) {
            cout << num << " ";
        }
        cout << endl;
        return;
    }
    int prevElement = -1;

    for (int i = index; i < set.size(); i++) {
        if (prevElement != set[i]) {
            if (set[i] + currentSum > target) break;
            possibleAns.push_back(set[i]);
            prevElement = set[i];
            helper(set, target, i + 1, currentSum + set[i], possibleAns);
            possibleAns.pop_back();
        }
    }
}

void findSubset(vector<int>& set, int target) {
    sort(set.begin(), set.end());
    vector<int> possibleAns;
    helper(set, target, 0, 0, possibleAns);
}

int main() {
    vector<int> set = {1, 2, 5, 6, 8};
    findSubset(set, 9);
    return 0;
}
