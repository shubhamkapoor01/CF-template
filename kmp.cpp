class Solution {
private:
    vector<int> getLPS(string& s, int m) {
        vector<int> lps(m, 0);
        int prev = 0;
        int curr = 1;
        
        while (curr < m) {
            if (s[prev] == s[curr]) {
                lps[curr] = prev + 1;
                curr ++;
                prev ++;
                
            } else {
                if (prev) {
                    prev = lps[prev - 1];
                    
                } else {
                    lps[curr] = 0;
                    curr ++;
                }
            }
        }
    
        return lps;
    }
    
public:
    int KMP(string s, string p) {
        int n = s.size();
        int m = p.size();
        
        vector<int> lps = getLPS(p, m);
        
        int i = 0;
        int j = 0;
        
        while (i < n) {
            if (s[i] == p[j]) {
                i ++;
                j ++;
                
                if (j == m) {
                    return i - m;
                }
                
            } else {
                if (j) {
                    j = lps[j - 1];
                    
                } else {
                    i ++;
                }
            }
        }
        
        return -1;
    }
};
