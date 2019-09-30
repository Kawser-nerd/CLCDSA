N=int(input())
S=input()
count=S[1:].count('E')
ans=S[1:].count('E')
for i in range(N-1):
  count+=(S[i].count('W')-S[i+1].count('E'))
  ans=count if count<ans else ans
print(ans)