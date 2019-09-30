def query(a, b):
    print("? {} {}".format(a, b))
    return int(input())


N = int(input())
ans = 0
v = 1

for i in range(2, N + 1):
    dist = query(1, i)
    if ans < dist:
        ans = dist
        v = i

for i in range(1, N+1):
    if i == v:
        continue
    ans = max(ans, query(v, i))

print("!", ans)