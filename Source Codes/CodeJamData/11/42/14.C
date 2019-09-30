#include<iostream>
#include<fstream>
#include<cstring>
#include<cmath>
#include<map>
#include<vector>
#include<algorithm>
#include<iterator>
#include<sstream>
#include<set>
#include<deque>
using namespace std;

typedef unsigned long long uint64;
typedef long long int64;
typedef long double ld;

#define p_b push_back
#define all(c) (c).begin(), (c).end()
#define tr(container, it) for(typeof(container.begin()) it = container.begin();it!=container.end();it++)
#define present(container, element) ((container).find(element)!=(container).end())
#define cpresent(container, element) (find(all(container),element)!=container.end())

const int MAX=15;
int A[MAX][MAX];

int main(int argc, char *argv[])
{
//readin file
	string file;
	if(argc!=2){cerr<<"0,1 or 2!"<<endl;exit(1);}
	switch(atoi(argv[1]))
	{
		case 0: file="test"; break;
		case 1: file="B-small"; break;
		case 2: file="B-large"; break;
		default: cerr<<"choose the correct file, 0(test),1(small),2(large)"<<endl;exit(1); break;
	}
	string ifilename=file+".in"; string ofilename=file+".out";
	ifstream input(ifilename.c_str());ofstream output(ofilename.c_str());

//read in number of events
	int NCase;
	input>>NCase;
	int64 R,C,D;

//main loop start
	for(int ncase=0;ncase<NCase;ncase++)
	{
		cout<<"case : "<<ncase+1<<endl;
		output<<"Case #"<<ncase+1<<": ";

		input>>R>>C>>D;
		char tmp;
		for(int i=0;i<R;i++)
			for(int j=0;j<C;j++)
			{
				input>>tmp;
				A[i][j]=tmp-'0';
//				cout<<A[i][j];
			}

		int Kmax=min(R,C);
		int KK=0;
		for(int r1=0;r1<=R-3;r1++)
			for(int c1=0;c1<=C-3;c1++)
			{
				for(int k=3;k<=Kmax;k++)
				{
					if(r1+k>R || c1+k>C)continue;
					//check
					int64 cx=0,cy=0;
					int64 m=0;

//					cout<<r1<<' '<<c1<<' '<<k<<endl;
					for(int i=r1;i<r1+k;i++)
						for(int j=c1;j<c1+k;j++)
						{
//							cout<<i<<' '<<j<<endl;
							if(i==r1 && j==c1)continue;
							if(i==r1 && j==c1+k-1)continue;
							if(i==r1+k-1 && j==c1)continue;
							if(i==r1+k-1 && j==c1+k-1)continue;

							cx += (A[i][j])*i;
							cy += (A[i][j])*j;
							m += A[i][j];
						}

					if((fabs((double)cx-(double)m*r1-(double)m*(k-1)/2.0) < 1e-5) && (fabs((double)cy-(double)m*c1-(double)m*(k-1)/2.0)<1e-5 ))
//					if(fabs((double)cx/m - r1 -(k-1)/2.0)<1e-2  && fabs((double)cy/m -c1 -(k-1)/2.0)<1e-2)
					{
						if(k>KK){KK=k;}
					}
				}
			}
		if(KK==0)output<<"IMPOSSIBLE"<<endl;
		else output<<KK<<endl;
	}

	input.close();
	output.close();
	return 0;
}
