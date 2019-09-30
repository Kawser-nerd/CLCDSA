N = int(input())
t = [int(input()) for i in range(N)]
min_t = 10 ** 9
for bit in range(1<<N):
    A = []
    B = []
    for i in range(N):
        if bit & (1<<i):
            A.append(t[i])
        else:
            B.append(t[i])
    min_t = min(min_t, max(sum(A), sum(B)))
print(min_t)