class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        int sum = 0;
        vector<int> run;
        for (auto x : nums) {
            sum += x;
            run.push_back(sum);
        }
        return run;
    }
};

// TC: O(N), SC: O(N) - or we can also say O(1), since the answer expects a output array

class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        // [1, 2, 3, 4]
        // [1, 3, 6, 10]

        int n = nums.size();
        for (int i = 1; i < n; i++) {
            nums[i] = nums[i] + nums[i - 1];
        }

        return nums;
    }
};

// TC: O(N), SC: O(1)