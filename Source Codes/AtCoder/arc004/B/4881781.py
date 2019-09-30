n = int(input())
d = [int(input()) for _ in range(n)]

print(sum(d))

d_max = max(d)
others = sum(d) - d_max

if d_max <= others:
    print(0)
else:
    print(d_max - others)