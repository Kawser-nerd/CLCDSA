n = int(input())
a = []
for _ in range(n):
    city, num = input().split()
    a.append((int(num), city))
a.sort()
if ((a[-1][0] * 2) > sum(list(map(lambda x: x[0], a)))):
    ans = a[-1][1]
else:
    ans = "atcoder"
print(ans)