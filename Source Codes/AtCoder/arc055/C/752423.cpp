#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

double dp[1080];

void z_algorithm(string str, int* Z){
	const int L = str.size();

	for(int i=1, left=0, right=0; i<L; i++){
		if(i > right){
			left = right = i;
			for(;right < L && str[right-left] == str[right]; right++);
			Z[i] = right - left;
			right--;
		}
		else{
			int k = i - left;
			if(Z[k] < right - i + 1){
				Z[i] = Z[k];
			}
			else{
				left = i;
				for(;right < L && str[right-left] == str[right]; right++);
				Z[i] = right - left;
				right--;
			}
		}
	}
}

int Za[2160000], Zb[2160000];

int main(){
	string str, strop;
	cin >> str;
 	int n = str.size();
	long long int res = 0;
	z_algorithm(str, Za);
	for(int i = str.size() - 1;i >= 0;i--){
		strop += str[i];
	}                    
	
	z_algorithm(strop, Zb);
                                                          
	for(int i = n-2;i >= 0;i--){
		if(i <= n - i)break;
		res += max(0, min(Za[i], (n-i-1)) + min(Zb[(n-i)], (n-i-1))- (n-i) + 1);
	}	
	
	cout << res << endl;
	return 0;

}