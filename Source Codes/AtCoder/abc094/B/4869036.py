n, m, x = map(int, input().split())
A = list(map(int, input().split()))
r = l = 0
for i in A:
    if i > x:
        r += 1
    else:
        l += 1
print(min(r, l))