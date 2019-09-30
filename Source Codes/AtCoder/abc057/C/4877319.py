n=int(input());ans=10
for i in range(min(10**5,n)):
  if n%(i+1)==0:ans=min(ans,max(len(str(i+1)),len(str(n//(i+1)))))
print(ans)