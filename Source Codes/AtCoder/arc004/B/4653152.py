n = int(input())
s = 0
mi = float('inf')
d = []
for i in range(n):
    a = int(input())
    s += a
    d.append(a)

ma = max(d)
q = s - ma

print(s)
print(max(0, ma - q))