N = int(input())
P = [int(input()) for _ in range(N)]
Index = [None] * N
Used = set()
Chain = [1] * N

for i in range(N):
    p = P[i]
    Index[p-1] = i
    Used |= {p}
    if p-1 in Used:
        Chain[i] = Chain[Index[p-2]] + 1

print(N - max(Chain))