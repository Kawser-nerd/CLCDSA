n=int(input())
x=list(map(int,input().split()))
p=x[:]
p.sort()
s=p[n//2]
t=p[n//2-1]
for i in range(n):
    if x[i]<=t:
        print(s)
    else:
        print(t)