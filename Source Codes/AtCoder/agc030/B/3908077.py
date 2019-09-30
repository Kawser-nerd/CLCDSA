# -*- coding: utf-8 -*-
"""
Created on Sun Dec 30 09:04:16 2018

@author: Yamazaki Kenichi
"""
L,N = map(int, input().split(' '))
X = [int(input()) for i in range(N) ]

#inp = input().split()
#inp = [int(i) for i in inp]
#L, N = inp[0],inp[1]
#X = inp[2:]

X = [0] + X 
temp = L - X[1]
ans =  temp

itr1 = 0
itr2 = N

a = N%2

for i in range(-(N-1),N):
    if (i+a)%2 == 1:
        itr1 += 1
    else:
        itr2 -= 1

    if X[i]-X[i-itr1] >=0:
        minus = X[i]-X[i-itr1]
    else:
        minus = L+(X[i]-X[i-itr1])

    if X[i+itr2]-X[i] >=0:
        plus = X[i+itr2]-X[i]
    else:
        plus = L+(X[i+itr2]-X[i])
    temp = temp - minus + plus
#    print(temp)
    ans = max(ans,temp)
print(ans)