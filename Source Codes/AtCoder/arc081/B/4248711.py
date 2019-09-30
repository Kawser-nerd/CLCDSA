N,S,T=int(input()),input(),input()
A=[int(S[i]==T[i])for i in range(N) if not i or S[i-1]!=S[i]]
a,d=6-3*A[0],len(A)-1
if d:
 for i in range(d):
  b,c=A[i+1],A[i]
  a*=3+2*c*b-2*b-c
print(a%(10**9+7))