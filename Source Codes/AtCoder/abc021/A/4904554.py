n = int(input())
s = bin(n)[2:]
cnt = 0
ls = []
for i in range(len(s)-1,-1,-1):
  if s[i] == "1":
    cnt += 1
    ls.append((2 ** (len(s)-1 - i)))
print(cnt)
for i in range(cnt):
  print(ls[i])