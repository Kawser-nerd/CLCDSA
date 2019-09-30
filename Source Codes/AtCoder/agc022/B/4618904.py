from random import sample
n=int(input())
if n==3:
    ans=[2,5,63]
else:
    L=[]
    for i in range(6,30001):
        if i%2==0 or i%3==0:
            L.append(i)
    while True:
        ans=[2,3,4]
        ans+=sample(L,n-3)
        if not sum(ans)%6:
            break
print(*ans)