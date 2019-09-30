#include<iostream>
using namespace std;

int main()
{
    char a[110], b[110], c[110];
    char ans[3] = {'A','B','C'};
    int x = 0, y = 0, z = 0;
    int flag = 0;
    int p=0;
    int mm = 0;
    cin >> a >> b >> c;

    while (1) {
        if (flag == 0) {
            flag = 1;
            x = -1;
            y = -1;
            z = -1;
        }
        if (mm == 0) {
            x++;
            if (a[x] == 'a')mm = 0;
            else if (a[x] == 'b')mm = 1;
            else if (a[x] == 'c')mm = 2;
            if (a[x] == '\0') {
                p = 0;
                break;
            }
        }
        else if (mm == 1) {
            y++;
            if (b[y] == 'a')mm = 0;
            else if (b[y] == 'b')mm = 1;
            else if (b[y] == 'c')mm = 2;
            if (b[y] == '\0') {
                p = 1;
                break;
            }

        }else if (mm == 2) {
            z++;
            if (c[z] == 'a')mm = 0;
            else if (c[z] == 'b')mm = 1;
            else if (c[z] == 'c')mm = 2;
            if (c[z] == '\0') {
                p = 2;
                break;
            }
     
        }
    }

    cout << ans[p] << endl;

    return 0;
}