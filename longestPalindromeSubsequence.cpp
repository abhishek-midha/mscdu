#include<bits/stdc++.h>
using namespace std;

int longestPalindromeSubseq(string s) {
        int n=s.size();

        if(n==0) return 0;
        if(n==1) return 1;
        
        vector<vector<int>>opt(n+1, vector<int>(n+1,0));

        string b=s;
        reverse(b.begin(), b.end());
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(s[i-1]==b[j-1]){
                    opt[i][j]=1+opt[i-1][j-1];
                }
                else{
                    opt[i][j]=max(opt[i-1][j], opt[i][j-1]);
                }
            }
        }
        return opt[n][n];
    }


int main()
{
    int ans=longestPalindromeSubseq("bbbab");
    cout<<ans;
}