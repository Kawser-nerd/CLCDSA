#import collections as c
#ip = lambda : map(int, input().split())

#################
K=int(input())
al = [int(i) for i in input().split()]

s,l = 2,2

if al[-1] != 2:
    print(-1)
    exit()
if K==1:
    print(s,l+al[0]-1)

for i in range(K-1,-1,-1):
    c = 0
    if s%al[i-1]==0:
        tmps = s
    else:tmps = s + al[i-1] - s%al[i-1]
    if tmps <= l+al[i]-1:
        s = tmps
        c+=1
        l = (l+al[i]-1)//al[i-1]*al[i-1]

    if c==0:
        print(-1)
        exit()
    if i==1:
        print(s,l+al[0]-1)