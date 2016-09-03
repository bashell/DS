#include <iostream>
#include <vector>

using std::vector;
using std::cout; using std::endl;

#define max(a,b) ( (a)>(b) ? (a):(b) )


/**
 * T(n) = O(N*W)
 * 
 * @param N: Num of kinds of items
 * @param W: Capacity of knapsack
 */
int knapsack(vector<int> &weight, vector<int> &value, int N, int W) {
  int dp[N+1][W+1];
  for(int i = 0; i <= N; ++i) {
    for(int j = 0; j <= W; ++j) {
      if(i == 0 || j == 0)  // no item or the capacity of knapsack is zero
        dp[i][j] = 0;
      else if(weight[i-1] <= j)  // as for value[i-1], two cases: including or excluding
        dp[i][j] = max(dp[i-1][j], value[i-1] + dp[i-1][j-weight[i-1]]);
      else  // can't put value[i-1] into knapsack
        dp[i][j] = dp[i-1][j];
    }
  }
  return dp[N][W];
}


int main()
{
  vector<int> weight{10, 20, 30, 40};
  vector<int> value{100, 300, 350, 420};
  int N = value.size(), W = 60;
  cout << knapsack(weight, value, N, W) << endl;
  return 0;
}
