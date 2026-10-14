class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        if(num == 1 && sum >= 10) return "";
        if(sum > 9 * num) return "";
        string ans = "";
        while(num>0){
            if(sum >= 9) {
                sum -= 9;
                ans += to_string(9); 
            }
            else if(sum < 9 && num > 0) {
                ans += to_string(sum);
                sum -= sum;
            }
            num--;
        }
        return ans;
    }
};