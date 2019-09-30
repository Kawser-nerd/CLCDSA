s = input()
l = len(s) - 2
n = 999

for i in range(l):
  tmp = abs(753 - int(s[i]+s[i+1]+s[i+2]))
  if (tmp < n):
    n = tmp;

print(n)