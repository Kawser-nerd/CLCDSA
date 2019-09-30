n = int(input())
ans = float("inf")
for i in range(1000):
  for j in range(1000):
      if i*j>n:
         continue
      else:
        if ans>n-(i*j)+abs(i-j):
           ans=n-(i*j)+abs(i-j)
print(ans)