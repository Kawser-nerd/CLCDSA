l = [chr(i) for i in range(97,97+26)]
s = []
for _ in [0]*int(input()):
  s.append(input())
w = ""
for x in l:
  a = [t.count(x) for t in s]
  w += x*min(a)
print(w)