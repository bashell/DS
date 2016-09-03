#include <iostream>
#include <vector>

using std::vector;

/**
 * Longest Increasing Subsequence
 *
 * T(n) = O(n^2)
 * S(n) = O(n)
 */
int lengthOfLis(vector<int> &ivec) {
  int len = ivec.size(), max;
  if(len <= 1)
    return len;
  // lisHelper[i] represents the max length of subsequence end with ivec[i]
  vector<int> lisHelper(len, 1);  
  for(int i = 1; i < len; ++i) 
    for(int j = 0; j < i; ++j)
      if(ivec[i] > ivec[j] && lisHelper[i] < lisHelper[j]+1)
        lisHelper[i] = lisHelper[j] + 1;
  max = lisHelper[0];
  for(auto val : lisHelper)
    if(max < val)
      max = val;
  return max;
}

int main()
{
  vector<int> ivec{21, 30, 15, 18, 19, 36, 15, 22, 50};
  std::cout << "Length of LIS is " << lengthOfLis(ivec) << std::endl;
  return 0;
}
