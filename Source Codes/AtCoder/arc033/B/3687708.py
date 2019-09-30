input()
l=set(map(int,input().split()))
m=set(map(int,input().split()))
a=len(l&m)
s=len(l)+len(m)-a
print(a/s)