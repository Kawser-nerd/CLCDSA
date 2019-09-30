S=input()
block=0
for i in range(len(S)):
  if i==0:
    block+=1
  elif S[i]!=S[i-1]:
    block+=1
print(block-1)