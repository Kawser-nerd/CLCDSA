#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>
#pragma GCC optimize ("O3")

inline static long gl(void){
    long x = 0;
    for(;;){
        unsigned int c = getchar_unlocked() - 48;
        if(c < 10){
            x = x*10 + c;
        }else{
            break;
        }
    }
    return x;
}

inline static void pl(unsigned int s){
    char str[10];
    int pos=9;
    if(s==0){
        putchar_unlocked('0');
        return;
    }
    str[pos] = '\n';
    do{
        pos--;
        str[pos]=s%10+48;
        s/=10;
    }while(s!=0);
    write(1, str+pos, 10-pos);
}

inline static int sp(unsigned char* str, unsigned short i){
    if(i>99){
        str[2] = i%10+48; i/=10;
        str[1] = i%10+48;
        str[0] = i/10+48;
        return 3;
    }else if(i>9){
        str[1] = i%10+48;
        str[0] = i/10+48;
        return 2;
    }else{
        str[0] = i+48;
        return 1;
    }
}

unsigned char a[2*500*500];
unsigned char buffer[8*1024*1024];

int main(void){
    const unsigned long h=gl(), w=gl();
    fread(a, 1, 2*w*h, stdin);
    unsigned long p=0, pos=0;
    unsigned char *aa = a-2; 
    {
        bool haveCoin = false;
        unsigned short old_y, old_x;
        for(unsigned long i=1; i<=h; i++){
            if(i%2==1){
                for(unsigned long j=1; j<=w; j++){
                    if(haveCoin){
                        pos++;
                        p += sp(buffer+p, old_y)+1; buffer[p-1] = ' '; 
                        p += sp(buffer+p, old_x)+1; buffer[p-1] = ' '; 
                        p += sp(buffer+p, i)+1; buffer[p-1] = ' '; 
                        p += sp(buffer+p, j)+1; buffer[p-1] = '\n';
                    }
                    haveCoin = aa[2*j]&1 ? !haveCoin : haveCoin;
                    old_y = i;
                    old_x = j;
                }
            }else{
                for(long j=w; j>0; j--){
                    if(haveCoin){
                        pos++;
                        p += sp(buffer+p, old_y)+1; buffer[p-1] = ' '; 
                        p += sp(buffer+p, old_x)+1; buffer[p-1] = ' '; 
                        p += sp(buffer+p, i)+1; buffer[p-1] = ' '; 
                        p += sp(buffer+p, j)+1; buffer[p-1] = '\n';
                    }
                    haveCoin = aa[2*j]&1 ? !haveCoin : haveCoin;
                    old_y = i;
                    old_x = j;
                }
            }
            aa+=2*w;
        }
    }
    pl(pos);
    //fwrite(buffer, 1, p, stdout);
    write(1, buffer, p);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:56:5: warning: ignoring return value of ‘fread’, declared with attribute warn_unused_result [-Wunused-result]
     fread(a, 1, 2*w*h, stdin);
     ^
./Main.c:95:5: warning: ignoring return value of ‘write’, declared with attribute warn_unused_result [-Wunused-result]
     write(1, buffer, p);
     ^
./Main.c: In function ‘pl’:
./Main.c:32:5: warning: ignoring return value of ‘write’, declared with attribute warn_unused_result [-Wunused-result]
     write(1, str+pos, 10-pos);
     ^