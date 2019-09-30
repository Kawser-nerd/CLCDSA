L, R = map(int, input().split())
left = [int(_) for _ in input().split()]
right = [int(_) for _ in input().split()]
res = 0

for i in range(10, 41):
    res += min(left.count(i), right.count(i))

print(res)