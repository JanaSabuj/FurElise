class Solution {
public:
    int longestPalindrome(string str) {
        map<char, int> mp;
        for (auto x : str) {
            mp[x]++;
        }

        int len = 0;
        int one = 0;

        for (auto x : str) {
            if (mp[x] % 2 == 0) {
                len += mp[x];
                mp[x] = 0;
            } else {
                len += (mp[x] - 1);
                mp[x] = 1;
                one++;
            }
        }

        return len + (one > 0 ? 1 : 0);
    }
};
// ----------
// better would be to iterate over the hashmap
// even -> take it all
// odd -> take all but 1
class Solution {
public:
    int longestPalindrome(string str) {
        unordered_map<char, int> mp;
        for (auto x : str) {
            mp[x]++;
        }

        int len = 0;
        int one = 0;

        for (auto kv : mp) {
            if (kv.second % 2 == 0)
                len += kv.second;
            else {
                len += (kv.second - 1);
                one++;
            }
        }

        return len + (one > 0 ? 1 : 0);
    }
};