class Solution {
public:
    vector<int> dp;
    int fibo(int n){
        if(n<=1) return n;
        if(dp[n]!=0) return dp[n];
        int ans = fibo(n-1)+fibo(n-2);
        dp[n]= ans;
        return ans;
    }

    int fib(int n) {
        dp.resize(n+1,0);
        return fibo(n);
    }
};