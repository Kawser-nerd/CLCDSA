n=int(input())
ans=0
for i in range(40):
  if i**2 <= n and ans<=i**2:
    ans=i**2
  if i**3 <= n and ans<=i**3:
    ans=i**3
  if i**5 <= n and ans<=i**5:
    ans=i**5
  if i**7 <= n and ans<=i**7:
    ans=i**7
print(ans)