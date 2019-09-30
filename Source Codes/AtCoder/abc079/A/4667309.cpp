#include <iostream>
#include <cstring>
#include <stdio.h>

using namespace std;


int main()
{

	int n,c,cif;
	int nr = 1;
	cin >> n;
	c = n % 10;
	n = n / 10;
	while(n != 0) {
		cif = n % 10;
		if(cif == c)
            {
                nr++;
                c = cif;
            }
        else
        {
            nr = 1;
            c = cif;
        }
		if(nr == 3)
            {
                cout << "Yes";
                return 0;
            }

		n = n / 10;

	}
	cout<<"No";

}