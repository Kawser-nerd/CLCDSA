N, M = map(int, input().split())
a = [int(input()) for _ in range(M)]
a = a[::-1] + [int(i) for i in range(1, N+1)]
L = set()

for i in a:
    if i not in L:
        print(i)
        L.add(i)