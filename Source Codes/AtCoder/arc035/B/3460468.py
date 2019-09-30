# -*- coding: utf-8 -*-
# ??????
import math

N = int(input())
a = []
ans = 0
for i in range(N):
	a.append(int(input()))
a.sort(reverse = True)
for i in range(N):
	ans += a[i]*(i+1)
dic = {}
for i in range(N):
	if(a[i] in dic):
		dic[a[i]] = dic[a[i]]+1 
	else:
		dic[a[i]] = 1
ansb = 1
for i in dic.keys():
	x = 1
	for i in range(dic[i]):
		 x = (x*(i+1))%1000000007
	ansb = (ansb*x)%1000000007
print(ans)			
print(ansb)