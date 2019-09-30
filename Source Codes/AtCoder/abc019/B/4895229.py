def solve():
  s = input()
  n = len(s)
  ans = ""
  ct = 1
  for i in range(0,n):
    if ans == "": 
      ans += s[i]
      ct = 1
    elif ans[-1] == s[i]:
      ct+= 1
    elif ans[-1] != s[i]:
      ans += str(ct)
      ans += s[i]
      ct = 1
  ans +=str(ct)
  print(ans)
solve()