#include <iostream>
#include <cmath>

int n;
int x[500];
int l[500*500];//[,)
int r[500*500];//(,]
int a[500*500];

int main()
{
	std::cin >> n;
	for(int i = 0;i < n; ++i){
		std::cin >> x[i];
	}
	
	for(int i = 1;i <= n; ++i){
		auto pos = x[i-1]-1;
		a[pos] = i;
		l[pos] = i-1;
		r[pos] = n - i;
	}
	int space_count = 0;
	int* a_iter = a;
	//l???
	for(int i = 0;i < n*n; ++i){
		if(l[i] == 0){
			if(a[i] == 0) ++space_count;
		}
		else{
			if(l[i] <= space_count){
				//??????
				for(int j = 0;j < l[i]; ++j){
					while(*a_iter != 0){++a_iter;}
					*a_iter = a[i];
				}
				space_count -= l[i];
			}
			else{
				//??????
				std::cout << "No" << std::endl;return 0;
			}
		}
	}
	space_count = 0;
	a_iter = a+(n*n)-1;
	//r???
	for(int i = (n*n)-1;i >= 0; --i){
		if(r[i] == 0){
			if(a[i] == 0) ++space_count;
		}
		else{
			if(r[i] <= space_count){
				//??????
				for(int j = 0;j < r[i]; ++j){
					while(*a_iter != 0){--a_iter;}
					*a_iter = a[i];
				}
				space_count -= r[i];
			}
			else{
				//??????
				std::cout << "No" << std::endl;return 0;
			}
		}
	}
	
	std::cout << "Yes" << std::endl;
	for(int i = 0;i < n*n; ++i){
		std::cout << a[i] << ' ';
	}
}