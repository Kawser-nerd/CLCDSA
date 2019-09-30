s = list(input())
K = int(input())
n = len(s)

s1 = list(set(s.copy()))
s1.sort()
for i in range(5):
  s.append('')

if(len(s1) >=3):  n1 = 3
else:  n1 = len(s1)
first = []
for i in range(n1):
  first.append(s1[i])

s2 = []
for i in range(n):
  for j in first:
    if(s[i] == j):
      s2.append(s[i]),s2.append(s[i]+s[i+1]),s2.append(s[i]+s[i+1]+s[i+2])
      s2.append(s[i]+s[i+1]+s[i+2]+s[i+3]),s2.append(s[i]+s[i+1]+s[i+2]+s[i+3]+s[i+4])
s2 = list(set(s2))
s2.sort()
ans = s2[K-1]
print(ans)