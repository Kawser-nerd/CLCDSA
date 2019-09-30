# coding: utf-8
# Your code here!

N = int(input())
lst = [None]*N
for i in range(N):
    lst[i] = list(map(int,input().split()))
ans = 0
for i in range(N):
    for k in range(i,N):
        x = (lst[i][0]-lst[k][0])**2 
        y = (lst[i][1]-lst[k][1])**2
        tmp = (x+y)**0.5
        ans = max(ans,tmp)

print('{:.6f}'.format(ans))