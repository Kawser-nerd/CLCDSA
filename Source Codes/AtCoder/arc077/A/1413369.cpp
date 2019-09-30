#include<iostream>
#include<vector>

using namespace std;

int main(void)
{
    int n;
    vector<int> a;
    bool flag = true;

    cin>>n;

    for(int i = 0;i < n;i++) {
	int temp;
	
	cin>>temp;

	if(flag)
	    a.insert(a.begin(),temp);
	else
	    a.insert(a.end(),temp);

	flag = !flag;
    }

    if(n % 2 == 0)
	for(int i = n;i > 0;i--)
	    cout<<a[i-1]<<" ";
    else
	for(int i = 0;i < n;i++)
	    cout<<a[i]<<" ";

    return 0;
}