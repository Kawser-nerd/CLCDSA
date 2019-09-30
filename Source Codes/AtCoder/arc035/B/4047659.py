N=int(input())

T=[0 for i in range(10001)]
for i in range(N):
    t=int(input())
    T[t]+=1
    
anst=0
ansp=1
t=0
for i in range(len(T)):
    if T[i]>=1:
        for j in range(1,T[i]+1):
            anst+=t+i
            t+=i
            ansp*=j
            ansp%=(10**9+7)
print(anst)
print(ansp)