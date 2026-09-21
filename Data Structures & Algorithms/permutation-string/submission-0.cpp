class Solution {
    bool isSamefreq(int freq[26],int winfreq[26]){
        for(int i=0;i<26;i++){
            if(freq[i]!=winfreq[i]){
                return false;
            }
        }
        return true;
    }
public:
    bool checkInclusion(string s1, string s2) {
        int freq[26]={0};
        
        //1st we cal the frequency of numver in array
        for(int i=0;i<s1.length();i++){
            freq[s1[i]-'a']++;
        }

        //now we iterate the windowsize to that s2 string to window size
        for(int i=0;i<s2.length();i++){
            int windowindex=0;
            int actualindex=i;
            int winfreq[26]={0};
            while(windowindex<s1.length() && actualindex<s2.length()){
               winfreq[s2[actualindex]-'a']++;
               windowindex++;
               actualindex++;
            }

            if(isSamefreq(freq,winfreq)){
                return true;
            }
        }
        return false;
        
    }
};
