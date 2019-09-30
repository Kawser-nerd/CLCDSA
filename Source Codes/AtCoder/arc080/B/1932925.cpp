#include<iostream>
using namespace std;

int main()
{
	int H,W,N,sum = 0,s = 1;
	cin >> H >> W >> N;
    int* a = new int[H * W];
	int* b = new int[N];
	for(int i = 0;i < N;i++)
	{
		cin >> b[i];
		for(int k = 0;k < b[i];k++)
		    a[sum + k] = i + 1;
		sum = sum + b[i];	
    }
    while(s <= H)
    {
        if(s % 2 == 1)
        {
            for(int x = (s - 1) * W;x < s * W - 1;x++)
			    cout << a[x] <<" ";
		    cout << a[s * W - 1] << endl;
		    s++;
	    }
	    else if(s % 2 == 0)
	    {
		    for(int x = s * W - 1;x > (s - 1) * W;x--)
		        cout << a[x] << " ";
		    cout << a[(s - 1) * W] << endl;
		    s++;
	    }
    }
    delete []a;
    delete []b;
    return 0;
}