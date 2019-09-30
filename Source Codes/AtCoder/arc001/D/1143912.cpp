#include<iostream>
#include<cstdio>
using namespace std;
int check(int i, int j, int k, int l, int m, int n, int o, int p)
{
        return (i != j) && (i != k) && (i != l) && (i != m) && (i != n) && (i != o) && (i != p)
                && (j != k) && (j != l) && (j != m) && (j != n) && (j != o) && (j != p)
                && (k != l) && (k != m) && (k != n) && (k != o) && (k != p)
                && (l != m) && (l != n) && (l != o) && (l != p)
                && (m != n) && (m != o) && (m != p)
                && (n != o) && (n != p)
                && (o != p)
                && (abs(i - j) != 1) && (abs(j - k) != 1) && (abs(k - l) != 1) && (abs(l - m) != 1)
                && (abs(m - n) != 1) && (abs(n - o) != 1) && (abs(o - p) != 1)
                && (abs(i - k) != 2) && (abs(j - l) != 2) && (abs(k - m) != 2) && (abs(l - n) != 2)
                && (abs(m - o) != 2) && (abs(n - p) != 2)
                && (abs(i - l) != 3) && (abs(j - m) != 3) && (abs(k - n) != 3) && (abs(l - o) != 3)
                && (abs(m - p) != 3)
                && (abs(i - m) != 4) && (abs(j - n) != 4) && (abs(k - o) != 4) && (abs(l - p) != 4)
                && (abs(i - n) != 5) && (abs(j - o) != 5) && (abs(k - p) != 5)
                && (abs(i - o) != 6) && (abs(j - p) != 6)
                && (abs(i - p) != 7);
}
void printl(int i){
        for(int x = 0; x < 8; x++){
                cout << ((x==i)? "Q" : ".");
        }
        cout << endl;
}
void print(int i, int j, int k, int l, int m, int n, int o, int p)
{
        printl(i);
        printl(j);
        printl(k);
        printl(l);
        printl(m);
        printl(n);
        printl(o);
        printl(p);
}
int scanl(){
        char buf[100];
        scanf("%s",buf);
        for(int i=0;i<8;i++){
                if(buf[i]=='Q') return i;
        }
        return -1;
}
int main()
{
        int si,sj,sk,sl,sm,sn,so,sp;
        si = scanl();
        sj = scanl();
        sk = scanl();
        sl = scanl();
        sm = scanl();
        sn = scanl();
        so = scanl();
        sp = scanl();
        if(
                        (si == -1) +
                        (sj == -1) +
                        (sk == -1) +
                        (sl == -1) +
                        (sm == -1) +
                        (sn == -1) +
                        (so == -1) +
                        (sp == -1) != 5
                        ) goto end;
        int i, j, k, l, m, n, o, p;
        for (i = 0; i < 8; i++) {
                if(si!=-1&&si!=i) continue;
                for (j = 0; j < 8; j++) {
                        if(sj!=-1&&sj!=j) continue;
                        for (k = 0; k < 8; k++) {
                                if(sk!=-1&&sk!=k) continue;
                                for (l = 0; l < 8; l++) {
                                        if(sl!=-1&&sl!=l) continue;
                                        for (m = 0; m < 8; m++) {
                                                if(sm!=-1&&sm!=m) continue;
                                                for (n = 0; n < 8; n++) {
                                                        if(sn!=-1&&sn!=n) continue;
                                                        for (o = 0; o < 8; o++) {
                                                                if(so!=-1&&so!=o) continue;
                                                                for (p = 0; p < 8; p++) {
                                                                        if(sp!=-1&&sp!=p) continue;
                                                                        if (check(i, j, k, l, m, n, o, p)) {
                                                                                print(i, j, k, l, m, n, o, p);
                                                                                return 0;
                                                                        }
                                                                }
                                                        }
                                                }
                                        }
                                }
                        }
                }
        }
end:
        cout << "No Answer" << endl;
}