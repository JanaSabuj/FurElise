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
*/