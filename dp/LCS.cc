#include <iostream>
#include <vector>
#include <string>

using std::vector;
using std::string;

#define max(a,b) ( (a)>(b) ? (a):(b) )

/*
 * Longest Common Subsequece
 *
 * T(m,n) = O(m*n)
 * S(m,n) = O(m*n)
 */
int lengthOfLcs(const string &s1, const string &s2, int m, int n) {
  vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
  for(int i = 0; i <= m; ++i) {
    for(int j = 0; j <= n; ++j) {
      if(i == 0 || j == 0)
        dp[i][j] = 0;
      else if(s1[i-1] == s2[j-1])
        dp[i][j] = 1 + dp[i-1][j-1];
      else
        dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
    }
  }
  return dp[m][n];
}

int main()
{
  string word1("helloWorld");
  string word2("HelloWoRld");
  std::cout << "Length of LCS is " << lengthOfLcs(word1, word2, word1.size(), word2.size()) << std::endl;
  return 0;
}
