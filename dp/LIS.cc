#include <iostream>
#include <vector>

using std::vector;

/*
 * Longest Increasing Subsequence
 */
int lengthOfLis(vector<int> &ivec) {
  int len = ivec.size(), max = 0;
  if(len <= 1)
    return len;
  vector<int> lisHelper(len, 1);
  for(int i = 1; i < len; ++i) 
    for(int j = 0; j < i; ++j)
      if(ivec[j] < ivec[i] && lisHelper[j] + 1 > lisHelper[i])
        lisHelper[i] = lisHelper[j] + 1;
  for(auto val : lisHelper)
    if(max < val)
      max = val;
  return max;
}

int main()
{
  vector<int> ivec{21, 30, 15, 18, 19, 36, 15, 22, 50};
  std::cout << "Lenght of LIS is " << lengthOfLis(ivec) << std::endl;
  return 0;
}
