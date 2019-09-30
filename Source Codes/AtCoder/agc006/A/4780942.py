n = int(input())
s = input().strip()
t = input().strip()
is_match = False
for i in range(len(s)):
  if s[i:] == t[:n-i]:
    is_match = True
    break
if is_match:
  print(len(s[:i] + t))
else:
  print(len(s + t))