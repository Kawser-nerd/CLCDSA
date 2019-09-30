# -*- coding utf-8 -*-

n,k =map(int,input().split())

if n==1:
    print(n*k)
else:
   print(k*(k-1)**(n-1))