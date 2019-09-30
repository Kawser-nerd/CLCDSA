N = int(input())
d = [int(input()) for i in range(N)]

d.sort()

result1 = sum(d)
result2 = max(d[-1] - sum(d[:-1]), 0)

print(result1)
print(result2)