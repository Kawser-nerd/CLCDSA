n, s, t = [int(i) for i in input().split()]
w = int(input())
c = 0
if ((w >= s) & (w <= t)):
    c += 1
for _ in range(n-1):
    w += int(input())
    if ((w >= s) & (w <= t)):
        c += 1
print(c)