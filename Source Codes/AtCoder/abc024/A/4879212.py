a, b, c, k = [int(i) for i in input().split()]
s, t = [int(i) for i in input().split()]
d = a * s + b * t
if (s+t >= k):
    d -= (s+t) * c
print(d)