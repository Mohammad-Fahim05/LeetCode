class Solution {
public:
   long long solve(long long x , long long n){
    if(n == 0) return 1;
    long long half = solve(x , n/2);
    long long result = (half * half) % 1000000007;
    if(n%2 == 1) result = (result * x) % 1000000007;
    return   result;
   }
    int countGoodNumbers(long long n) {
        long long even = (n+1)/2;
        long long odd = n/2;
        return solve(5, even) * solve(4, odd)  % 1000000007;
 }
};