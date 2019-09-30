# -*- codng utf-8 -*-

n=int(input())
t=list(map(int,input().split()))
m=int(input())
T=sum(t)

for i in range(m):
    p,x=map(int,input().split())
    print(T-(t[p-1]-x))