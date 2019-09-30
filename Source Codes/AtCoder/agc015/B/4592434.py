s = input()
n = len(s)
d = 0
for i in range(n):
  if s[i] == "U":
    d += n+i-1
  else:
    d += n*2-i-2
print(d)