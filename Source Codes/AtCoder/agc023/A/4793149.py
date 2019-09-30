import collections
n = int(input())
a = [int(i) for i in input().split()]
s = [a[0]]
for i in range(1,n):s.append(s[i-1]+a[i])
c = collections.Counter(s)
d = [i*(i-1)//2 for i in c.values()]
print(sum(d)+c[0])