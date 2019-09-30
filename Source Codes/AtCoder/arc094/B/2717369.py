from math import sqrt 
Q = int(input())
table=[]
for i in range(Q):
    A,B=map(int,input().split())
    if A>B:
        table.append([B,A])
    else:
        table.append([A,B])
def f(a,b):
    if a==b:
        return 2*a-2
    if a+1==b:
        return 2*a-2
    m = int(sqrt(a*b))
    if m**2 ==a*b:
        m-=1
    if m*(m+1) >= a*b:
        return 2*m -2
    return 2*m-1

ans = []
for a,b in table:
    ans.append(f(a,b))
print('\n'.join(map(str,ans)))