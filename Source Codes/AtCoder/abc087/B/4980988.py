a,b,c,x=[int(input()) for i in range(4)]
ans=0
for i in range(a+1):
  for j in range(b+1):
    if 0<=(x-500*i-100*j)/50<=c:
      ans+=1
print(ans)