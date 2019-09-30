Q=int(input())
Qs=[list(map(int,input().split())) for _ in range(Q)]
Prime=[0]*100001
count=0

def Isprime(i):
    for j in range(2,int(i**(0.5))+1):
        if i%j==0:
            return False
    return True

for i in range(3, 100001, 2):
    if Isprime(i) and Isprime((i+1)//2):
        Prime[i]=1
        count+=1

for i in range(1,100001):
    Prime[i]=Prime[i]+Prime[i-1]

for q in Qs:
    print(Prime[q[1]]-Prime[q[0]-1])