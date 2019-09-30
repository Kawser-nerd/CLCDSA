n = int(input())
s = input()
ans = len(s)
wc = 0
ec = s.count('E')
for i in range(len(s)):
  if (s[i] == 'E'):
    ec -= 1
  if (ans > ec + wc):
    ans = ec + wc
  if (s[i] == 'W'):
    wc += 1
print(ans)