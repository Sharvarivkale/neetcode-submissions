class Solution {
public:
    int characterReplacement(string s, int k) {
                int left = 0;
        int maxFreq = 0;
        int ans = 0;

        int freq[26] = {0};

        for (int right = 0; right < s.length(); right++) {

            // Increase frequency of current character
            freq[s[right] - 'A']++;

            // Maximum frequency in current window
            maxFreq = max(maxFreq, freq[s[right] - 'A']);

            // Characters that need to be replaced
            int replace = (right - left + 1) - maxFreq;

            // If replacements are more than k, shrink window
            if (replace > k) {
                freq[s[left] - 'A']--;
                left++;
            }

            // Current valid window length
            ans = max(ans, right - left + 1);
        }

        return ans;

        
    }
};
