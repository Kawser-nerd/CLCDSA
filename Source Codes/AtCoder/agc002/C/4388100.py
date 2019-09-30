import sys
input = sys.stdin.readline
inf = float("inf")

n,L = map(int,input().split())
a = tuple(map(int,input().split()))

for i in range(1,n):
    if a[i]+a[i-1]>=L:
        print('Possible')
        for j in range(1,i):
            print(j)
        for j in range(n-1,i,-1):
            print(j)
        print(i)
        exit()

print('Impossible')