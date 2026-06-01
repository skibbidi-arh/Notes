#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int BinarySearch(const vector<int>& nums, int target, int left, int right) {
        if (left > right) {
            return -1;
        }
        int mid = left + (right - left) / 2;
        if (nums[mid] == target) {
            return mid;
        } else if (nums[mid] < target) {
            return BinarySearch(nums, target, mid + 1, right);
        } else {
            return BinarySearch(nums, target, left, mid - 1);
        }
    }
    int search(const vector<int>& nums, int target) {
        return BinarySearch(nums, target, 0, nums.size() - 1);
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 3, 5, 7, 9, 11};
    int target=7;

    int idx = sol.search(nums, target);
    if (idx != -1) {
        cout << "Target found at index " << idx << endl;
    } else {
        cout << "Target not found." << endl;
    }
    return 0;
}
