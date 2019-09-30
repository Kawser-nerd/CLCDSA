#include <cstdio>
#include <vector>

using namespace std;

int main(){
	int N, *heat, count = 0;
	scanf("%d", &N);
	heat = new int[N];
	for(int i = 0; i < N; i++)
		heat[i] = 0;

	for(int i = 0; i < N; i++){
		int value;
		scanf("%d", &value);
		for(int j = 0; j < N; j++){
			if(heat[j] >= value){
				heat[j] = value;
				break;
			}
			if(heat[j] == 0){
				heat[j] = value;
				count++;
				break;
			}
		}
	}
	delete[] heat;
	printf("%d\n", count);
	return 0;

}