class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        //  0 1 2 3 4 5
        // [1,  7,  3,  6,  5,  6]
        // pl: [0,  1,  8,  11, 17, 22] pl[i] = pl[i-1] + arr[i-1]
        // rl: [27.  20  17  11. 6.  0 ]


        // [1 2 3]
        // [0 1 3]
        // [5 3 0]


        // [2,1,-1] -> [0 2 3] [0 -1 0]
        // [0,2,3]
        // [0,-1,0]
        int n = nums.size();
        int pl[n], rl[n];

        for (int i = 0; i < n; i++) {
            if (i == 0) pl[i] = 0;
            else pl[i] = pl[i - 1] + nums[i - 1];
        }

        for (int i = n - 1; i >= 0; i--) {
            if (i == n - 1) rl[i] = 0;
            else rl[i] = rl[i + 1] + nums[i + 1];
        }

        int idx = -1;
        for (int i = 0; i < n; i++) {
            if (pl[i] == rl[i]) return i;
        }
        return idx;
    }
};
// TC: O(N), SC: O(2N)

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        //  0 1 2 3 4 5
        // [1,  7,  3,  6,  5,  6]
        // pl: [0,  1,  8,  11, 17, 22] pl[i] = pl[i-1] + arr[i-1]
        // rl: [27.  20  17  11. 6.  0 ]

        // [1 2 3]
        // [0 1 3]
        // [5 3 0]

        // [2,1,-1] -> [0 2 3] [0 -1 0]
        // [0,2,3]
        // [0,-1,0]
        int n = nums.size();
        int tsum = 0;
        for (auto x : nums)
            tsum += x;

        int csum = 0;
        for (int i = 0; i < n; i++) {
            csum += nums[i];
            if (csum - nums[i] == tsum - csum) return i;// imp hack
        }
        return -1;
    }
};

// TC: O(N), SC: O(1)