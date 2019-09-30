#coding utf-8 -*-

lis=list(map(int,input().split()))
lis_1=sorted(lis)

if lis_1[2] - lis_1[1] == lis_1[1] - lis_1[0]:
    print("YES")
else:
    print("NO")