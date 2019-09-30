n, q = map(int, input().split())
s = input()
c = [0]
for i in range(len(s)-1):
  if s[i] == "A" and s[i+1] == "C":
    c.append(c[-1]+1)
  else:
    c.append(c[-1])
    
for i in range(q):
  l, r = map(int, input().split())
  print(c[r-1] - c[l-1])