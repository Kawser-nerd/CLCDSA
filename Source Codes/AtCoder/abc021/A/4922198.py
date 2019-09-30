n=int(input())
print(int(n/2) if n%2==0 else int(n/2)+1)
if n%2==1: print(1)
for i in range(int(n/2)):
  print(2)