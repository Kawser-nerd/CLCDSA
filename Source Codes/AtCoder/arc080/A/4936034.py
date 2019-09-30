n=int(input())
a=[int(i) for i in input().split()]
#print(n,a)

m=n//2
cnt=0
for i in range(n):
  if a[i]%2==0:
    cnt+=1
    if a[i]%4==0:
      cnt+=1

print('Yes' if cnt>=2*m else 'No')