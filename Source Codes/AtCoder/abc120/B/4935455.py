m = list(map(int, input().split()))
a = m[0]
b = m[1]
k = m[2]
c = min(a, b)
d = 0
e = 0

for i in range(c):
    if(a % (c - i) == 0 and b % (c - i) == 0):
        d += 1
    if(d == k):
        e = c - i
        break
print(e)