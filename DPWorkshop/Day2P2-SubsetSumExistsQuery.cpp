/*
	For Q queries,
		Check if subset exists in arr X with sum as Ti,
		Print the subset

		N <= 100
		xi <= 1e4
		T <= 1e4

Problem with the previous approacH:
+ TC increases
+ cant use same DP array multiple times, bcox dp[level][S] depends on Ti bcoz Ti is used in the dp
+ have to print, and not say 0/1

Soln:
- To reomove dependency of rec func on Ti, we use sum_left as state instead of sum_taken
- dp[level][sum_taken] -----> dp[level][sum_left] (this is cacheabale across queries)
-

	TC: O(N*T*Q) drops to O(N*T + Q)
*/

#include <bits/stdc++.h>
// #include<iostream>
using namespace std;
#define crap ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
const int N = 101;
int x[N];
int n, T;
int dp[101][1001];

int rec(int level, int time_left) {
	// pruning
	if (time_left < 0)
		return 0;

	// basecase
	if (level == n) {
		if (time_left == 0)
			return 1;
		else
			return 0;
	}

	// dp check
	if (dp[level][time_left] != -1)
		return dp[level][time_left];

	// compute
	int isPoss = rec(level + 1, time_left) || rec(level + 1, time_left - x[level]);

	// save and return
	return dp[level][time_left] = isPoss;
}

void solve() {
	cin >> n >> T;
	for (int i = 0; i < n; i++) {
		cin >> x[i];
	}
	memset(dp, -1, sizeof(dp)); // O(S) + O(DP) - only 1 flush of DP across all queries

	int q;
	cin >> q;

	while (q--) {
		int tt;
		cin >> tt;
		cout << rec(0, tt) << endl;
	}
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