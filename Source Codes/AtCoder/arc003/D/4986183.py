import sys
input=sys.stdin.readline
from time import time
from random import randint

start=time()
n,m,k=map(int,input().split())
AB=[tuple(map(int,input().split())) for _ in range(m)]

def judge(num,Rn=[i for i in range(n)],K=range(k),l=n,L=AB):
    for _ in range(num):
        *R,=Rn
        for _ in K:
            a=randint(0,l-1)
            b=randint(0,l-2)
            b+=a<=b
            tmp=R[a]
            R[a]=R[b]
            R[b]=tmp
        for a,b in L:
            d=abs(R[a]-R[b])
            if d==1 or d==l-1:
                yield 0
                break
        else:
            yield 1

def prob(num,t):
    border=start+t
    u,v=0,0
    while True:
        u+=sum(judge(num))
        v+=num
        if time()>border:
            break
    return u,v

def main():
    num=150000
    p=sum(judge(num)); q=num
    u,v=prob(10000,9.4)
    p+=u; q+=v
    u,v=prob(1000,9.8)
    p+=u; q+=v
    u,v=prob(100,9.97)
    p+=u; q+=v
    print(p/q)

main()