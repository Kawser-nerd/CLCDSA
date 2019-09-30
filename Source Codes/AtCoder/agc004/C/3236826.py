# coding:utf-8

INF = float('inf')


def inpl(): return list(map(int, input().split()))


H, W = inpl()

X = [list(input()) for _ in range(H)]

A = [['.' for _ in range(W)] for _ in range(H)]
B = [['.' for _ in range(W)] for _ in range(H)]
tmp = ['#' for _ in range(W - 1)]
for i in range(H):
    if i % 2 == 0:
        A[i][:-1] = tmp
        B[i][-1] = '#'
    else:
        B[i][1:] = tmp
        A[i][0] = '#'

for h in range(H):
    for w in range(W):
        if X[h][w] == '#':
            A[h][w] = '#'
            B[h][w] = '#'

for a in A:
    print(''.join(a))
print('')
for b in B:
    print(''.join(b))