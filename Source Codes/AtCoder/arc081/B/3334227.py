N = int(input())
s1 = input()
s2 = input()
i = 0
pat = []
while i < N:
  if s1[i]==s2[i]:
    pat.append('t')
    i += 1
  else:
    pat.append('y')
    i += 2
if pat[0]=='t':
  ans = 3
else:
  ans = 6
pat2 = pat[1:]
l = len(pat)
i = 1
while i < l:
  if pat[i]=='t' and pat[i-1]=='t':
    ans = (ans*2)%(10**9+7)
  elif pat[i]=='t' and pat[i-1]=='y':
    pass
  elif pat[i]=='y' and pat[i-1]=='t':
    ans = (ans*2)%(10**9+7)
  elif pat[i]=='y' and pat[i-1]=='y':
    ans = (ans*3)%(10**9+7)
  i += 1
print(ans)