N, M, X = map(int, input().split())
a = list(map(int, input().split()))
l = 0
r = 0
for i in a:
    if X > i:
        l += 1
    else:
        r += 1
print(min(l, r))