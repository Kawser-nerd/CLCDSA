N=int(input())
A = [int(a) for a in input().split()]

d = {}
for a in A:
  d[a] = d.get(a,0) + 1
B = [0,0]
for k in d:
  if d[k] >= 4:
    B.append(k)
    B.append(k)
  elif d[k] >=2:
    B.append(k)
B.sort()
print(B[-1]*B[-2])