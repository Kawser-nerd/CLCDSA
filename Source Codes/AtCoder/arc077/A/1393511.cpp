#include "cstdio"
#include "math.h"
#include <vector>

int main()
{
	int n;
	scanf("%d", &n);
	std::vector<int> arr(n);

	int origin = (int)(ceil((float)n / 2)) - 1;
	int expand = 0;
	bool even = n % 2 == 0;
	for (int i = 0; i < n; i++){
		int a;
		scanf("%d", &a);
		if (i % 2 == 0) {
			if (even) {
				arr[origin - expand] = a;
			} else {
				arr[origin + expand] = a;
			}
		} else {
			expand++;
			if (even) {
				arr[origin + expand] = a;
			} else {
				arr[origin - expand] = a;
			}
		}
	}
	std::reverse(arr.begin(), arr.end());
	for (int i = 0; i < n; i++){
		printf("%d ", arr[i]);
	}
	printf("\n");

	return 0;
}