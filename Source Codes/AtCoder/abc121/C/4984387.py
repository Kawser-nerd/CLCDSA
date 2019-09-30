import sys

n, m = list(map(int, input().split()))
l = [list(map(int, input().split())) for i in range(n)]

l.sort()
ans=0
tot=0

for i in range(n):
    for j in range(l[i][1]):
        ans+=1
        tot+=l[i][0]
        if(m <= ans):
            print(tot)
            sys.exit()