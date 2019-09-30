n=int(input())
T=list(map(int,input().split()))
m=int(input())
for i in range(m):
    p,k=map(int,input().split())
    tmp=T[p-1]
    T[p-1]=k
    print(sum(T))
    T[p-1]=tmp