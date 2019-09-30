#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main()
{
  long double x_a, y_a, x_b, y_b, x_c, y_c;
  cin >> x_a >> y_a >> x_b >> y_b >> x_c >> y_c;

  cout << fixed << setprecision(3) << fabs((x_b-x_a)*(y_c-y_a) - (y_b-y_a)*(x_c-x_a)) / 2.0 << endl;
}