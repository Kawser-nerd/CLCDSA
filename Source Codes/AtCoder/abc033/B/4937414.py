n=int(input())
S=[]
P=[]
for i in range(n):
  s,p=input().split()
  S.append(s)
  P.append(int(p))
print("atcoder" if 2*max(P)<=sum(P) else S[P.index(max(P))])