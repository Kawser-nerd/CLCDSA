S=input()
n=len(S)
r=0
for i in range(n//2):
  for j in range(1,n//2):
    if i+j*2>=1+n:continue
    if S[i:i+j]==S[i+j:i+2*j]:r=max(r,j)
print(r*2)