N=int(input())
P=[int(input()) for i in range(N)]
P=sorted(P,reverse=True)
P[0]=P[0]//2
print(sum(P))