n, m = map(int, input().split())
L = [i for i in range(n+1)]

for _ in range(m):
    i = int(input())
    # L[0] = i
    # L.index[i] = L[0]
    j = L.index(i)
    L[0], L[j] = i, L[0]


for i in range(1, n+1):
    print(L[i])