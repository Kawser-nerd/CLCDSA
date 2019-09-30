N, M = map(int, input().split())
zahyo = list(map(int, input().split()))
zahyo.sort()
sa = [0 for _ in range(M-1)]

for i in range(M-1):
    sa[i] = zahyo[i+1] - zahyo[i]

sa.sort(reverse=True)
sa = sa[N-1:]

print(sum(sa))