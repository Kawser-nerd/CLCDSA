n, x = map(int, input().split())
if x == 1 or x == (2 * n - 1):
    print("No")
    exit()

print("Yes")

r = [x - 1, x, x + 1]
tmp = list(range(1, x - 1)) + list(range(x + 2, 2 * n))

ans = tmp[n - 2:] + r + tmp[:n - 2]

for i in ans:
    print(i)