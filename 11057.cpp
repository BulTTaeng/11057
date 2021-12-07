#include <iostream>

using namespace std;

int dp[2][10];

#define MOD 10007

int main() {
  int n;
  cin >> n;

  for(int i =0; i<= 9 ; i++){
    dp[0][i] = 1;
  }

  for(int i =1; i<n; i++){
    dp[i%2][0] = 1;
    for(int j =1; j<=9; j++){
      dp[i%2][j] = (dp[i%2][j-1] + dp[1 - (i%2)][j]) % MOD ; 
    }
  }
  int ans = 0;

  for(int i =0; i<=9;i++){
    ans += dp[(n-1)%2][i] ;
  }
  
  ans = ans % MOD;

  cout << ans;
  return 0;


}