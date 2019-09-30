N = int(input())
a = list(map(int, input().split())) + [0]
c = [0] * (N + 2)
for i in range(N):
    c[i + 1] = abs(a[i] - a[i - 1])
c[-1] = abs(a[-2])
s = sum(c)
for i in range(N):
    print(s - c[i + 1] - c[i + 2] + abs(a[i + 1] - a[i - 1]))