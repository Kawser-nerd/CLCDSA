n,x = map(int,input().split())

if x == n:
  print("Yes")
  for i in range(1,2*n):
    print(i)
    
elif 1 < x < n:
  print("Yes")
  for i in range(x+1,n+1):
    print(i)
  for i in range(1,x+1):
    print(i)
  for i in range(n+1,2*n):
    print(i)

elif n < x < 2*n-1:
  print("Yes")
  for i in range(1,n):
    print(i)
  for i in range(x,2*n):
    print(i)
  for i in range(n,x):
    print(i)

else:
  print("No")