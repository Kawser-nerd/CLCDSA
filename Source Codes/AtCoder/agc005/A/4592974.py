S=input()
N=len(S)
ans=N

stack=[]
stack.append(S[0])
for i in range(1,N):
  if len(stack)!=0 and stack[len(stack)-1]=='S' and S[i]=='T':
    ans-=2
    stack.pop()
  elif S[i]=='S':
    stack.append(S[i])

print(ans)