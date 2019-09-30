import sys
n,m = map(int, input().split())
for i in range(n+1):
    b = 4*n-2*i-m
    if isinstance(b, int) and n-i-b>=0 and b>=0:
        print(i,b,n-i-b)
        sys.exit()
print(-1,-1,-1)