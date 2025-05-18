#include <bits/stdc++.h>
using namespace std;

// Helper function to find all combinations
// of size r in an array of size n
void combinationUtil(int ind, int r, vector<int> &data,
    vector<vector<int>> &result, vector<int> &arr) {
    int n = arr.size();

    // If size of current combination is r
    if (data.size() == r) {
        result.push_back(data);
        return;
    }

    // Replace index with all possible elements
    for(int i = ind; i < n; i++) {

        // Current element is included
        data.push_back(arr[i]);

        // Recur for next elements
        combinationUtil(i + 1, r, data, result, arr);

        // Backtrack to find other combinations
        data.pop_back();
    }
}

// Function to find all combinations of size r
// in an array of size n
vector<vector<int>> findCombination(vector<int> &arr, int r) {
    int n = arr.size();

    // to store the result
    vector<vector<int>> result;

    // Temporary array to store current combination
    vector<int> data;
    combinationUtil(0, r, data, result, arr);
    return result;
}

int main()  {
    vector<int> arr = {1, 2, 3, 4};
    int r = 2;
    vector<vector<int>> res = findCombination(arr, r);
    for (const auto &comb : res) {
        for (int num : comb) {
            cout << num << " ";
        }
        cout << endl;
    }
    return 0;
}
