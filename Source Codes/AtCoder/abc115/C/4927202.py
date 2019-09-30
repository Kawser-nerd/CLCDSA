n,k=map(int,input().split())
h=[]
for i in range(n):
    a=int(input())
    h.append(a)

high=sorted(h)
sa=[]
for j in range(n-k+1):
    t=high[j+k-1]-high[j]
    sa.append(t)
print(min(sa))