Form 1 DP(LCCM - Level, Choice, Check, Move)
---------
1. Decide the framework

2. Decide the states and meaning
-----
Dp(level, ...[use info of the previous states]) = Dp(go the next levels)
so, when you come to a particular level, you already have info if you have taken or not taken the prev levels.
- The constraints given is the reason why 2^N subsets are not the ans, the ans is < 2^N bcoz every possible
answer must adhere to a constraint.
- DP(level, Ttaken, Itaken) = Max skill (desired ans form) gained in [level...N-1] with Ttaken,Itaken and the limit
being X and K respectively.

3. Decide the transition
DP(level, Ttaken, Iaken) = max(DP(level + 1, Ttaken, Itaken), 
							Skill[level] + DP(level + 1, Ttaken + T[level], Itaken + 1))

4. TC 
TC = count(States) * (1 + avg cost of transition)
   level[0..N]
   Ttaken[0...Sum(Ti)] == Ttaken[0...X] (further reduced by the given constraint)
   Itaken[0...N] == Itaken[0...K] (further reduced by the given constraint)
   O(N*X*K) * (1 + O(2))