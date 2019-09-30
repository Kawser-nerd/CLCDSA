n = int(input())
t = [ int(i) for i in input().split() ]
s = sum(t)
m = int(input())
for i in range(m):
    a,b = map(int,input().split())
    print( s - t[a-1] + b )