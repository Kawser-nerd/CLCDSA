# -*- coding: utf-8 -*-


if __name__ == '__main__':
    a=int(input())
    b=a+1
    a=a**2
    b=b**2
    k=1
    while((a+k-1)//k*k<b):
        n=(a+k-1)//k
        k*=100
    print(n)