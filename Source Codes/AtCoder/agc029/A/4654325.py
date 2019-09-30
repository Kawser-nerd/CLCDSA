count,ans = 0,0
s=input()
for i,c in enumerate(s):
  if c == 'W':
    ans += i - count
    count += 1
print(ans)