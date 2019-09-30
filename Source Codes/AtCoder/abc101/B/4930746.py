n=input()
sum=0
for i in range(len(n)):
  sum+=int(n[i])
print("Yes" if int(n)%sum==0 else "No")