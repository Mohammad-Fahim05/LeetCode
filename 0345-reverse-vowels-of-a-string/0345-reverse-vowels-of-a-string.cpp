class Solution {
public:

    bool isVowel(char x){
        if(x == 'a' || x == 'e' || x == 'i' || x=='o' || x == 'u' || x == 'A' || x == 'E' || x == 'I' || x == 'O' || x == 'U') return true;
        return false ;
    }
    string reverseVowels(string s) {
        int i = 0;
        int j = s.size()-1;
        while(i < j){
            if(!isVowel(s[i]) ){
            i++;
            }
            else if(!isVowel(s[j])) j--;
            else {
                swap(s[i],s[j]);
                i++;
                j--;
            }
        }
        return s;
    }
};