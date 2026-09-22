class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> need(128, 0), window(128, 0);
        for (char c : t) need[c]++;
        
        int required = 0;
        for (int i = 0; i < 128; i++) {
            if (need[i] > 0) required++;
        }
        
        int left = 0, matched = 0;
        int start = 0, minLen = INT_MAX;
        
        for (int right = 0; right < s.size(); right++) {
            char c = s[right];
            window[c]++;
            
            if (need[c] > 0 && window[c] == need[c]) {
                matched++;
            }
            
            while (matched == required) {
                if (right - left + 1 < minLen) {
                    start = left;
                    minLen = right - left + 1;
                }
                
                char d = s[left];
                window[d]--;
                if (need[d] > 0 && window[d] < need[d]) {
                    matched--;
                }
                left++;
            }
        }
        
        return minLen == INT_MAX ? "" : s.substr(start, minLen);
    }
};