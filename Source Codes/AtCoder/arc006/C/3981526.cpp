#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
	
	int n;scanf("%d",&n);
	
	vector<double> res;
	double temp;int jud=0;
	for(int i=0;i<n;i++){
		scanf("%f",&temp);
		jud=0;
		if(res.size()==0) {
			res.push_back(temp);continue;
		}
		
		for(int j=0;j<res.size();j++){
			if(res[j]>=temp) {
				res[j]=temp;
				jud=1;
				break;	
			}
		}
		if(jud==0) res.push_back(temp);
		
		sort(res.begin(),res.end());
	}
	
	printf("%d\n",res.size());
	return 0;
} ./Main.cpp:13:14: warning: format specifies type 'float *' but the argument has type 'double *' [-Wformat]
                scanf("%f",&temp);
                       ~~  ^~~~~
                       %lf
./Main.cpp:31:16: warning: format specifies type 'int' but the argument has type 'size_type' (aka 'unsigned long') [-Wformat]
        printf("%d\n",res.size());
                ~~    ^~~~~~~~~~
                %lu
2 warnings generated.