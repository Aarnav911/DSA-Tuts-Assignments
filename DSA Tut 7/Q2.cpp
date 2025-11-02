#include <iostream>
#include <vector>
using namespace std;
int main()
{
  vector<int> v = {5, 8, 4, 9, 2, 1, 7};
  int left = 0, right = v.size() - 1;
  while (left < right)
  {
    int min_index = left, max_index = right;
    for (int i = left; i <= right; i++)
    {
      if (v[i] < v[min_index])
        min_index = i;
      if (v[i] > v[max_index])
        max_index = i;
    }
    swap(v[left], v[min_index]);
    if (max_index == left)
      max_index = min_index;
    swap(v[right], v[max_index]);
    left++;
    right--;
  }
  for (int ele : v)
    cout << ele << " ";
  return 0;
}
