s = []
for _ in [0]*int(input()):
  s.append(input())
w = ""
for i in range(97,97+26):
  x = chr(i)
  a = [t.count(x) for t in s]
  w += x*min(a)
print(w)