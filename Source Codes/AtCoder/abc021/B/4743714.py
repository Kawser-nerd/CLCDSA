N=int(input())
x,y=map(int,input().split(' '))
K=int(input())
P=list(map(int,input().split(' ')))
P.append(x)
P.append(y)
Pa=set(P)

if len(Pa)!=len(P):
    print('NO')
else:
    print('YES')