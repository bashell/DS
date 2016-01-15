#include <iostream>
#include <algorithm>
#include <vector>

using std::vector;

void bucketSort(vector<float> &arr) {
  int n = arr.size();
  vector<float> tmp;
  vector<vector<float>> bucket;
  for(int i = 0; i < n; ++i)  // 创建n个空桶
    bucket.push_back(tmp);
  for(int i = 0; i < n; ++i) {  // 将arr中的元素添加到合适的桶中
    int index = n * arr[i];
    bucket[index].push_back(arr[i]);
  }
  for(int i = 0; i < n; ++i)  // 桶内排序
    std::sort(bucket[i].begin(), bucket[i].end());
  int index = 0;
  for(int i = 0; i < n; ++i)  // 合并桶
    for(int j = 0; j < bucket[i].size(); ++j)
      arr[index++] = bucket[i][j];  
}

int main()
{
    vector<float> test{0.78, 0.17, 0.39, 0.26, 0.72, 0.94, 0.21, 0.12, 0.23, 0.68};
    bucketSort(test);
    for(auto i : test)
      std::cout << i << " ";
    std::cout << std::endl;
    return 0;
}
