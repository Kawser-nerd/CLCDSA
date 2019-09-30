s = input()
k = int(input())

a = sorted(set(s))[:5]
if len(s) >= 2:
  b = sorted(set([s[i:i+2] for i in range(len(s)-1)]))[:5]
  a.extend(b)
if len(s) >= 3:
  c = sorted(set([s[i:i+3] for i in range(len(s)-2)]))[:5]
  a.extend(c)
if len(s) >= 4:
  d = sorted(set([s[i:i+4] for i in range(len(s)-3)]))[:5]
  a.extend(d)
if len(s) >= 5:
  e = sorted(set([s[i:i+5] for i in range(len(s)-4)]))[:5]
  a.extend(e)

print(sorted(a)[k-1])