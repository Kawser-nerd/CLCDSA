n = int(input())
s1 = input()
s2 = input()
mod = 10**9+7
b = 0
did = 0
ans = 0
if s1[0] == s2[0]:
  b = 1
  ans += 3
else:
  did = 1
  ans = 6
for i in range(1,n):
  if s1[i] == s2[i]:
    if b:
      ans = ans*2%mod
    b = 1
  elif not did:
    if b:
      ans = ans*2%mod
    else:
      ans = ans*3%mod
    did = 1
    b = 0
  else:
    did = 0
print(ans)