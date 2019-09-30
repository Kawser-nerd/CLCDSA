N = int(input())
_A1 = [int(x) for x in input().split()]
_A2 = [int(x) for x in input().split()]


A1 = [0] * (N)
A2 = [0] * (N)

for i in range(0, N):
    if i == 0:
        A1[i] = _A1[i]
        A2[i] = _A2[i]
    else:
        A1[i] = A1[i - 1] + _A1[i]
        A2[i] = A2[i - 1] + _A2[i]

sum = 0

for i in range(0, N):
    u = A1[i]
    if i == 0:
        d = A2[N - 1]
    else:
        d = A2[N - 1] - A2[i-1]
    sum = max(u+d, sum)

print(sum)