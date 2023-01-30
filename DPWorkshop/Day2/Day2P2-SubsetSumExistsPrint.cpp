/*
	Arr: [1, 2, 5, 9]
	T = 3
	T = 4
	T = 16

	How to keep track of which item to take or leave ?

	dp(1,16) -1(N.Take)-> dp(2, 16) -1(T)-> dp(3, 14) -1(T)-> dp(4,9) -1(T)-> dp(5,0)

	Trace the transitions to get the final flow - 1. Recheck 2. Backptr

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

void printset(int level, int time_left) {
	// basecase
	if (level == n) return;

	// compute
	if (rec(level + 1, time_left)) {// dont take
		printset(level + 1, time_left);
	} else if (rec(level + 1, time_left - x[level])) {// take
		cout << x[level] << " ";
		printset(level + 1, time_left - x[level]);
	}
}

void solve() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> x[i];
	}
	memset(dp, -1, sizeof(dp)); // O(S) + O(DP) - only 1 flush of DP across all queries

	int q;
	cin >> q;

	while (q--) {
		int tt;
		cin >> tt;
		if (rec(0, tt)) {
			printset(0, tt);
			cout << endl;
		} else {
			cout << "No Solution" << endl;
		}
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