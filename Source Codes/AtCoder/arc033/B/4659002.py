a,b=map(int,input().split())
A=list(map(int,input().split()))
B=list(map(int,input().split()))

X=len(set(A+B))
Y=len(A)+len(B)-X

print(Y/X)