N,K=map(int,input().split())
A=list(map(int,input().split()))
tp=[0]*121
for a in A:
    index=0
    while a!=0:
        tp[index]+=a%2
        a//=2
        index+=1
L=[i for i in range(len(tp)) if tp[i] <= N//2][::-1]
x = 0
for i in L:
    if x + 2**i <= K:
        x+=2**i
print(sum([x^i for i in A]))