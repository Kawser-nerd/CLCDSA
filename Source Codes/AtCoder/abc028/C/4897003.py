import itertools

X=list(map(int,input().split()))

A=list(itertools.combinations(X,3))

S=[]
for a in A:
    S.append(sum(a))

S.sort(reverse=True)

print(S[2])