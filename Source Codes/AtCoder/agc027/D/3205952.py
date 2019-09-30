import sys
#sys.stdin=open("data.txt")
input=sys.stdin.readline
mii=lambda:map(int,input().split())

# get primes
lim=10000
sieve=[1]*lim
prime=[]
for i in range(2,lim):
    if not sieve[i]: continue
    prime.append(i)
    for j in range(i*i,lim,i):
        sieve[j]=0

prime.sort()
prime=[i for i in prime if i>500]
prime=prime[:500]
li=[]
while prime:
    li.append(prime.pop(0))
    li.append(prime.pop(-1))
powers=li

# print matrix
n=int(input())
out=[[0 for j in range(n)] for i in range(n)]

s=set()
for i in range(n):
    for j in range(n):
        if (i+j)%2==0:
            # put small number
            out[i][j]=powers[(i+j)//2]*(i+1)
            if out[i][j] in s:
                print("why",i,j)
            s.add(out[i][j])

for i in range(n):
    for j in range(n):
        if (i+j)%2==1:
            # put big number
            big=i+1
            if i>0: big*=i
            if i<n-1: big*=i+2
            big*=powers[(i+j)//2]
            big*=powers[(i+j+1)//2]
            k=1
            while big*k+1 in s: k+=1
            out[i][j]=big*k+1
            s.add(out[i][j])


# checking
if 0:
    for i in range(n-1):
        for j in range(n):
            x=out[i][j]
            y=out[i+1][j]
            if x<y: x,y=y,x
            while x%y!=1: 1
            x=out[j][i]
            y=out[j][i+1]
            if x<y: x,y=y,x
            while x%y!=1: 1
    s=set()
    for i in out:
        for j in i:
            s.add(j)
    while len(s)!=n**2: 1
    while max(s)>10**15: 1
    while min(s)<1: 1

for li in out: print(" ".join(map(str,li)))