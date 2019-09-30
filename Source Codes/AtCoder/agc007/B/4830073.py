N = int(input())
p = list(map(int, input().split()))
q = [0] * N
for i in range(N):
    q[p[i] - 1] = i
for i in range(N):
    print(30000 * i + 1, end = "")
    if i == N - 1:
        print()
    else:
        print(end = " ")
for i in range(N):
    print(30000 * (N - i) + q[i] + 1, end = "")
    if i == N - 1:
        print()
    else:
        print(end = " ")