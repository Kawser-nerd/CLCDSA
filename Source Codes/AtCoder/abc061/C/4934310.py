import sys
fastinput=sys.stdin.readline
N,K=map(int,fastinput().split())
data=[[int(j) for j in fastinput().split()] for k in range(N)]
ab=sorted(data,key=lambda x:x[0])
number=0
for a,b in ab:
    number+=b
    if number>=K:
        print(a)
        break