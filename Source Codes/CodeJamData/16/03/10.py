
import sys,itertools
sys.stdin=open("data.txt")
sys.stdout=open("out.txt","w")
input=sys.stdin.readline

def divide(n):
    i=2
    while i<=7:
        if n%i==0: return i
        i+=1
    #while i*i<=n:
    #    if n%i==0: return i
    #    i+=1
    return 1

for case in range(int(input())):
    print("Case #%s:"%(case+1))
    n,coin=map(int,input().split())

    t=0
    while t<2**(n-2) and coin>0:
        k=t
        stuff=[]
        for j in range(n-2):
            stuff.append(k&1)
            k//=2
        i="1"+"".join(map(str,stuff[::-1]))+"1"
        nums=[]
        for j in range(2,11):
            nums.append(divide(int(i,j)))
        if min(nums)>1:
            print("%s %s"%(i," ".join(map(str,nums))))
            coin-=1
        t+=1