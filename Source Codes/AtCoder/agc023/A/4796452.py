n = int(input())
a = list(map(int,input().split()))

s = []
p = 0

for i in range(n):
    p+=a[i]
    s.append(p)
s.append(0)

x = 0
import collections
s = collections.Counter(s)

y,z = zip(*s.most_common())

for i in range(len(z)):
    x += (z[i]*(z[i]-1))//2
print(x)