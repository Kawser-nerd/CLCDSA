#include <iostream>
#include<sstream>
#include<vector>
#include<iterator>
int main(void)
{
	int N, Q;
    std::cin >> N >> Q;
    std::vector<int> table(N+1, 0);
	for(int i=0; i<Q; i++){
		int l, r;
        std::cin >> l >> r;

        table[l-1]++;
		table[r]--;
	}

	int sum = 0;
	for(int i=0; i<N; i++){
		sum += table[i];
		if(sum%2 == 0)
			std::cout << 0;
		else
			std::cout << 1;
	}

    std::cout << std::endl;
}