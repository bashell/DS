#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

/**
 * sieve of Eratosthenes
 */
vector<int> prime_table(int n) {
    vector<int> arr(n+1, 0);
    for(int i = 2; i <= n; ++i)
        arr[i] = i;
    for(int i = 2; i <= sqrt(n); ++i) {
        if(arr[i] != 0) {
            int j = i*i;
            while(j <= n) {
                arr[j] = 0;  // eliminated
                j += i;
            }
        }
    }
    vector<int> res;
    for(int i = 2; i <= n; ++i)
        if(arr[i] != 0)
            res.push_back(arr[i]);
    return res;
}

int main()
{
    int n;
    cin >> n;
    vector<int> ivec = prime_table(n);
    for(auto num : ivec)
        cout << num << " ";
    cout << endl;
    return 0;
}
