n = int(input())
s = n%9
l = n//9
if s == 0:
  s = 9
  l -= 1
ans = [str(s)]*(l+1)
print("".join(ans))