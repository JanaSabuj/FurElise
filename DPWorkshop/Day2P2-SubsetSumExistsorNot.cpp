/*
	Subset of Target Sum Exists or NOT?
	There are N items, x1, x2, ..., xN, find if a subset exists that sums up to a target T [N <= 100, xi <= 10^4]
	x1, x2, [x3, ..., xN]
			 ^
	dp(level, S) = if a subset exists from [level...N-1] such that S is the accumulated sum till now
	dp(level, S) = dp(level + 1, S) || dp(level + 1, S + x[level]) {dont take it || take it}
	Ans: dp(0, 0)
	TC: O(N * min(T ,{max(xi) * N})(1 + 2)
		= O(N * T) since T < max(xi) * N generally
*/

/*
	Sabuj Jana / @greenindia
	God is Great!
*/

#include <bits/stdc++.h>
// #include<iostream>
using namespace std;
#define crap ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
const int N = 101;
int x[N];
int n, T;
int dp[101][1001];

int rec(int level, int S) {
	// pruning
	if (S > T)
		return 0;

	// basecase
	if (level == n) {
		if (S == T)
			return 1;
		else
			return 0;
	}

	// dp check
	if (dp[level][S] != -1)
		return dp[level][S];

	// compute
	int isPoss = rec(level + 1, S) || rec(level + 1, S + x[level]);

	// save and return
	return dp[level][S] = isPoss;
}

void solve() {
	cin >> n >> T;
	for (int i = 0; i < n; i++) {
		cin >> x[i];
	}
	memset(dp, -1, sizeof(dp));
	cout << rec(0, 0) << endl;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	crap;

	int t = 1;
	// cin >> t;
	while (t--) {
		solve();
	}

	return 0;
}