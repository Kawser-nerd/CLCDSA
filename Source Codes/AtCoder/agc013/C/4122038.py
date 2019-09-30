iipt=lambda:int(input())
miipt=lambda: list(map(int, input().split()))

n,l,t=miipt()
a=[miipt() for i in range(n)]
d=0
for x,w in a:
    d+=(x+(t if w==1 else -t))//l
d=d%n

e=[(x+(t if w==1 else -t))%l for x, w in a]

e.sort()


for i in range(n):
    print(e[(d+i)%n])