a, b, c = map(int, input().split())
d = max(a, b)
l = []
for i in range(1,d+1):
  if a % i == 0 and b % i == 0:
    l.append(i)
print(l[len(l)-c])