class Solution {
public:
	bool isSubsequence(string s, string t) {
		int n = s.size(), m = t.size();
		// s = "ahg", t = "ahbgdc"
		int j = 0;// s counter
		for (int i = 0; i < m && j < n; i++) {
			if (t[i] == s[j]) j++;
		}

		return (j == n);
	}
};
// TC: O(M), SC: O(1)