#080-D
def IL(): return list(map(int,input().split()))
def SL(): return input().split()
def I(): return int(input())
def S(): return list(input())
n,c=IL()
imos=[[0]*30 for i in range(pow(10,5))]
for i in range(n):
    s,t,c=IL()
    for j in range(s-1,t):
        imos[j][c-1]=1
ans=0
for i in range(pow(10,5)):
    ans=max(ans,sum(imos[i]))
print(ans)