class Solution {
public:
    int characterReplacement(string s, int k) {
        //here used of left are only for the slid the window
        int left=0;
        int maxfreq=0;
        int freq[26]={0};
        int ans=0;

        //now iterate the window through all
        for(int right=0;right<s.length();right++){
            //frequency increase
           freq[s[right]-'A']++;

           //cal the max frequnecy
           maxfreq=max(maxfreq,freq[s[right]-'A']);

           //now cal the what we want to replace
           int windowsize=right-left+1;
           int replace=windowsize-maxfreq;
           

           //if number of replace is greater than k then slide the window
           if(replace>k){
            freq[s[left]-'A']--;
            left++;
           }
           
           ans=max(ans,right-left+1);
        }
        return ans;
        
        
    }
};
