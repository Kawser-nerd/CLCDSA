s=input()
N=len(s)
ans=N//2
for i in range(N//2+1,N):
  if s[N-i:i]=="0"*(2*i-N) or s[N-i:i]=="1"*(2*i-N):
    ans=i
if s=="0"*N or s=="1"*N:
  ans=N
print(ans)