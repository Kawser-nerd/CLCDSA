#include <cstdio>
#include <algorithm>
#include <vector>
#include <cassert>
#include <cctype>
using namespace std;

int dp[50][10];

int nSol[51];

void fillDP()
{
	for (int i=0; i<10; i++)
	{
		dp[0][i] = 1;
		
		if (i+9 < 10)
			dp[1][i] = 4;
		else if (i+4 < 10)
			dp[1][i] = 3;
		else if (i+1 < 10)
			dp[1][i] = 2;
		else
			dp[1][i] = 1;
	}
	
	dp[0][0] = 0;
	
	for (int n=2; n<50; n++)
	{
		for (int s=0; s<10; s++)
		{
			dp[n][s] = 0;
			
			dp[n][s] += dp[n-2][s];
			if (s + 2 < 10)
				dp[n][s] += dp[n-2][s+2];
			if (s + 8 < 10)
				dp[n][s] += dp[n-2][s+8];
		}
	}
	
	nSol[0] = 0;
	nSol[1] = 3;
	for (int n=2; n<=50; n++)
	{
		nSol[n] = dp[n-2][2] + dp[n-2][8];
	}
}

int solStrictBelowNum(vector<int> num)
{
	int k = num.size();
	
	if (k == 1)
	{
		if (num[0] == 0)
			return 0;
		if (num[0] == 1)
			return 0;
		if (num[0] == 2)
			return 1;
		if (num[0] == 3)
			return 2;
		return 3;
	}
	
	int totSol = 0;
	
	for (int i=0; i<k; i++)
	{
		totSol += nSol[i];
	}
	
	for (int i=2; 2*i <= k; i++)
	{
		int s=0;
		for (int j=0; j<i-1; j++)
		{
			s += 2*num[k-j-1]*num[k-j-1];
		}
		
		if (s > 10)
			continue;
		
		for (int j=0; j<num[k-i] && s+j*j*2<10; j++)
			totSol += dp[k-2*i][s+j*j*2];
	}
	
	// handle special cases
	for (int j=1; j<num[k-1] && k >= 2 && j<=2; j++)
	{
		totSol += dp[k-2][2*j*j];
	}
	
	if (k % 2 == 1)
	{
		int s = 0;
		for (int i=0; 2*(i+1) < k; i++)
		{
			s += num[k-i-1]*num[k-i-1]*2;
		}
		
		for (int j=0; s+j*j < 10 && j < num[k/2]; j++)
		{
			totSol += 1;
		}
		
		bool isGood = false;
		int hw = k/2-1;
		
		for (int i=0; 2*i < k; i++)
		{
			if (num[hw-i] < num[hw+2+i])
			{
				break;
			}
			if (num[hw-i] > num[hw+2+i])
			{
				isGood = true;
				break;
			}
		}
		
		if (isGood && s + num[k/2]*num[k/2] < 10)
			totSol += 1;
	}
	else
	{
		int s = 0;
		for (int i=0; 2*i < k; i++)
		{
			s += num[k-i-1]*num[k-i-1]*2;
		}
		
		bool isGood = false;
		int hw = (k/2)-1;
		
		for (int i=0; i<k/2; i++)
		{
			if (num[hw-i] < num[hw+1+i])
			{
				break;
			}
			if (num[hw-i] > num[hw+1+i])
			{
				isGood = true;
				break;
			}
		}
		
		if (s < 10 && isGood)
			totSol += 1;
	}
	
	return totSol;
}

vector<int> sum(vector<int> a, vector<int> b)
{
	vector<int> c(max(a.size(), b.size()), 0);
	
	for (int i=0; i<a.size(); i++)
		c[i] += a[i];
	for (int j=0; j<b.size(); j++)
		c[j] += b[j];
	
	int carry = 0;
	for (int i=0; i<c.size(); i++)
	{
		c[i] += carry;
		carry = c[i] / 10;
		c[i] %= 10;
	}
	if (carry)
		c.push_back(carry);
	
	return c;
}

vector<int> dec(vector<int> a)
{
	a[0]--;
	int borrow = 0;
	for (int i=0; i<a.size(); i++)
	{
		a[i] -= borrow;
		borrow = 0;
		while(a[i] < 0)
		{
			a[i] += 10;
			borrow += 1;
		}
	}
	
	if (a[a.size()-1] == 0)
		a.resize(a.size()-1);
	
	assert(borrow == 0);
	return a;
}

vector<int> inc(vector<int> a)
{
	a[0]++;
	int carry = 0;
	for (int i=0; i<a.size(); i++)
	{
		a[i] += carry;
		carry = a[i]/10;
		a[i] %= 10;
	}
	if (carry)
		a.push_back(carry);
	
	return a;
}

vector<int> halve(vector<int> a)
{
	int k=a.size();
	int carry = 0;
	for (int i=0; i<k; i++)
	{
		int oc = carry;
		carry = (a[k-i-1] % 2)*5;
		a[k-i-1] /= 2;
		a[k-i-1] += oc;
	}
	
	carry=0;
	for (int i=0; i<k; i++)
	{
		a[i] += carry;
		carry = a[i] / 10;
		a[i] %= 10;
	}
	
	if (a[k-1] == 0 && k != 1)
		a.resize(a.size()-1);
	
	return a;
}

vector<int> square(vector<int> b)
{
	vector<int> result(1,0);
	vector<int> p;
	
	for (int i=0; i<b.size(); i++)
	{
		if (b[i] == 0)
			continue;
		p.resize(b.size()+i);
		for (int j=0; j<i; j++)
		{
			p[j] = 0;
		}
		for (int j=0; j<b.size(); j++)
		{	
			p[j+i] = b[j]*b[i];
		}
		
		int carry = 0;
		for (int i=0; i<p.size(); i++)
		{
			p[i] += carry;
			carry = p[i]/10;
			p[i] %= 10;
		}
		while (carry != 0)
		{
			p.push_back(carry % 10);
			carry /= 10;
		}
		
		result = sum(result, p);
	}
	
	return result;
}

bool isSmaller(vector<int> a, vector<int> b)
{
	if (a.size() > b.size())
		return false;
	if (a.size() < b.size())
		return true;
	
	int k = a.size();
	for (int i=0; i<k; i++)
	{
		if (a[k-1-i] > b[k-1-i])
			return false;
		if (a[k-1-i] < b[k-1-i])
			return true;
	}
	return false;
}

void print(vector<int> a)
{
	int k = a.size();
	for (int i=0; i<k; i++)
		printf("%d", a[k-1-i]);
	printf("\n");
}

vector<int> floorSqrt(vector<int> a)
{
	int k = a.size();
	
	if (k == 1 && a[0] < 2)
		return a;

	vector<int> low(1,0);
	vector<int> high = a;
	
	while (1)
	{
		vector<int> mid = halve(sum(low, high));
		
		if (!isSmaller(low, mid) && !isSmaller(mid, low))
			return low;
		
		if (isSmaller(a, square(mid)))
			high = mid;
		else
			low = mid;
	}
}

void doCase()
{
	char t;
	int k;
	vector<int> buf;
	vector<int> A;
	vector<int> B;
	
	// read first number:
	buf.resize(0);
	do
	{
		t = getchar();
	} while (isspace(t));
	do
	{
		assert(t >= '0' && t <= '9');
		buf.push_back(t-'0');
		t = getchar();
	} while (!isspace(t));
	k = buf.size();
	A.resize(k);
	for (int i=0; i<k; i++)
	{
		A[i] = buf[k-1-i];
	}
	
	// read second number:
	buf.resize(0);
	do
	{
		t = getchar();
	} while (isspace(t));
	do
	{
		assert(t >= '0' && t <= '9');
		buf.push_back(t-'0');
		t = getchar();
	} while (!isspace(t));
	k = buf.size();
	B.resize(k);
	for (int i=0; i<k; i++)
	{
		B[i] = buf[k-1-i];
	}
	
	printf("%d\n", max(0,solStrictBelowNum(inc(floorSqrt(B))) - solStrictBelowNum(inc(floorSqrt(dec(A))))));
}


int main()
{
	fillDP();
	
	int T;
	scanf("%d", &T);
	for (int i=1; i<=T; i++)
	{
		printf("Case #%d: ", i);
		doCase();
	}
	
	return 0;
}
