N = int(input())
P = [int(_) for _ in input().split()]
Q = P.copy()
count = 0
for i in range(N - 1):
    if P[i] == i + 1:
        count += 1
        P[i], P[i + 1] = P[i + 1], P[i]
if P[N - 1] == N:
    count += 1
print(count)