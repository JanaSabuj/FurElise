// ------------------------ 3. Skill Maximise Problem - { time[i], skill[i] } - maximise skill using X hrs and K slots
int t[1001], s[1001];
int x, k;
int n; // n workshops

int cache[101][101][101];

// rec[level][][] = max skill obtainable from arr[level..n-1] ... and parameters from arr[0...level-1]
int rec(int level, int time_taken, int item_taken) {
	// pruning

	// basecase
	if (level == n) return 0;// usually 0 is returned for finding MAX

	// dp check
	if (dp[level][time_taken][item_taken] != -1)
		return dp[level][time_taken][item_taken];

	// compute
	// choice1: dont take
	int maxskill = rec(level + 1, time_taken, item_taken);
	// choice2: take
	if (time_taken + t[level] <= x and item_taken + 1 <= k) {
		maxskill = max(maxskill, s[level] + rec(level + 1, time_taken + 1, item_taken + 1));
	}

	// save and return
	return dp[level][time_taken][item_taken] = maxskill;
}

memset(cache, -1, sizeof(cache));
// Ans: rec(0, 0, 0)