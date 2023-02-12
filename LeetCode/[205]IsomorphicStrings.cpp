class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int n = s.size();
        map<char, char> mp;// 1 - 1 mapping, treat this mapping as the source of truth
        set<char> st;// this will ensure that we dont corrupt our mapping

        for (int i = 0; i < n; i++) {
            if (mp.count(s[i]) == 0) {
                if (st.count(t[i]) == 0) {// 2 chars cant map to the same char
                    mp[s[i]] = t[i];// assume valid mapping 1 - 1
                    st.insert(t[i]);
                } else
                    return 0;
            } else if (mp[s[i]] != t[i])
                return 0;
        }

        return 1;
    }
};
// b->b, a->a, d->b,

/* if mapping D.N exist
        if end is not there in tracker:
            1-1 map start->end
            add end in tracker
        else
            return 0
    else
        if correct -> continue
        else -> return 0

*/
