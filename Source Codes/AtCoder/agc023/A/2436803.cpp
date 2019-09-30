// Atcoder Grand Contest 023 A ver 2.0
#include <iostream>
//#define DEBUG
using namespace std;

#ifdef DEBUG
void print_array_i(int* a, int l)
{
  for (int i=0; i<l; i++) {
    cout << a[i] << " ";
  }
  cout << endl;
}
void print_array_l(long long int* a, int l)
{
  for (int i=0; i<l; i++) {
    cout << a[i] << " ";
  }
  cout << endl;
}
#endif

int main()
{
  // ?????
  int n = 0;
  cin >> n;
  int array[n];
  for (int i=0; i<n; i++) {
    cin >> array[i];
  }

#ifdef DEBUG
print_array_i(array, n);
#endif

  // ??????
  long long int csum[n+1];
  csum[0]=0;
  for (int i=0; i<n; i++) {
    csum[i+1] = csum[i] + array[i];
  }

#ifdef DEBUG
print_array_l(csum, n+1);
#endif

  // ???????
  sort(csum, csum + n+1);

#ifdef DEBUG
print_array_l(csum, n+1);
#endif

  // ????????????
  long long int count=0, flag=0;
  long long int before = csum[0];
  for (int i=1; i<n+1; i++) {
    if (before == csum[i]) {
      count++;
      if (flag !=0 ) {
        count += flag;
      }
      flag++;
    } else {
      flag = 0;
    }
    before = csum[i];
  }

  // ?????
  cout << count << endl;
  return 0;
}