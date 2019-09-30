n=int(input())
stack=[0,0,0,0,0]
march=["M","A","R","C","H"]
for i in range(n):
  k=input()
  for j in range(5):
    if k[0]==march[j]:
      stack[j]+=1
      break
ans=0
for i in range(3):
  for j in range(i+1,4):
    for k in range(j+1,5):
      ans+=stack[i]*stack[j]*stack[k]
print(ans)