class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n1 = s1.size(), n2 = s2.size();
        if (n1 > n2) return false;

        vector<int> need(26, 0), window(26, 0);
        for (char c : s1) need[c - 'a']++;

        for (int i = 0; i < n1; i++) {
            window[s2[i] - 'a']++;
        }
        if (need == window) return true;

        for (int i = n1; i < n2; i++) {
            window[s2[i] - 'a']++;
            window[s2[i - n1] - 'a']--;
            if (need == window) return true;
        }

        return false;
    }
};