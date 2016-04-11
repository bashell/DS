#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using std::string;
using std::vector;

/*
 *  3 operations permitted: Insert / Delete / Replace
 */

int myMin(int x, int y, int z) {
  return std::min(std::min(x, y), z);
}

int EditDistanceHelper(string s1, string s2, int m, int n) {
  vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
  for(int i = 0; i <= m; ++i) {
    for(int j = 0; j <= n; ++j) {
      if(i == 0)
        dp[0][j] = j;
      else if(j == 0)
        dp[i][0] = i;
      else if(s1[i-1] == s2[j-1])  // last characters of two strings are same
        dp[i][j] = dp[i-1][j-1];
      else
        dp[i][j] = 1 + myMin(dp[i-1][j],     // Delete
                             dp[i][j-1],     // Insert
                             dp[i-1][j-1]);  // Replace
    }
  }
  return dp[m][n];
}

int EditDistance(string s1, string s2) {
  int len1 = s1.size(), len2 = s2.size();
  return EditDistanceHelper(s1, s2, len1, len2);
}

int main()
{
  string word1("hello World"), word2("Hello word");
  std::cout << EditDistance(word1, word2) << std::endl;
  return 0;
}
