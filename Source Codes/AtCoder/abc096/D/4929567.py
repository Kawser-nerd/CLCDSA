import sys
import math
def Sieve_of_Eratosthenes(N):
    prime=set(i for i in range(2,N+1))
    for i in range(2,math.ceil(N**0.5)+1):
        tmp=set()
        for j in prime:
            if j>i and j%i==0: tmp.add(j)
        for j in tmp:
            prime.remove(j)

    return(prime)

N=int(input())
prime=Sieve_of_Eratosthenes(55555)
ans=[[] for i in range(5)]
for i in prime:
    ans[i%5].append(i)

for i in range(N):
    print(ans[1][i],end=" ")