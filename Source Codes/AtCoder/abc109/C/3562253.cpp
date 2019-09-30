#include"iostream"
#include <string>
#include <numeric>

int distance(int x, int y)
{
  return std::abs(x-y);
}

int gcd(int a,int b)
{
	if (a%b==0)
	{
		return(b);
    }
	else
	{
		return(gcd(b,a%b));
    }
}

using namespace std;

int main(){

int N,X;
cin >> N >> X ;

int city;
cin >> city;
int Gcd = distance(city,X);
for(int i=1;i<N;i++)
{
  cin >> city;
  int dst = distance(city,X);
  Gcd = gcd(Gcd,dst);
}
  

cout << Gcd << endl;

return 0;
}