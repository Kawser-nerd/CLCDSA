/*#include<cstdio>
int main(){
    int hashTable[60] = {0};
    int n,x;
    int num;
    int count;
    scanf("%d",&n);
    for(int i = 0;i < n;i++){
        scanf("%d",&x);
        for(int k = 0;k < n;k++){
            if(hashTable[k] >= x){
                hashTable[k] = x;
                break;
            }
            if(hashTable[k] == 0){
                hashTable[k] = x;
                count++;
                break;
            }
        }
    }
    printf("%d\n",count);
    return 0;
}
*/

#include<cstdio>
using namespace std;
int const maxn = 1e5+10;
int hashTable[60] = {0};
int main(){
    int n;
    scanf("%d",&n);
    int index = 0;
    for(int i = 0;i < n;i++){
        bool flag = false;
        int temp;
        scanf("%d",&temp);
        for(int i = 0;i < index;i++){
            if(hashTable[i] >= temp){
                hashTable[i] = temp;
                flag = true;
                break;
            }
        }
        if(flag == false){
            hashTable[index++] = temp;
        }

    }
    printf("%d\n",index);
    return 0;

}