#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using std::vector;
using std::string;

/*
 * Longest Common Subsequece
 */
int lengthOfLcs(const string &s1, const string &s2, int m, int n) {
  vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
  for(int i = 0; i <= m; ++i) {
    for(int j = 0; j <= n; ++j) {
      if(i == 0 || j == 0)
        dp[i][j] = 0;
      else if(s1[i-1] == s2[j-1])
        dp[i][j] = dp[i-1][j-1] + 1;
      else
        dp[i][j] = std::max(dp[i][j-1], dp[i-1][j]);
    }
  }
  return dp[m][n];
}

int main()
{
  string word1("helloWorld");
  string word2("HelloWord");
  std::cout << "Length of LCS is " << lengthOfLcs(word1, word2, word1.size(), word2.size()) << std::endl;
  return 0;
}
