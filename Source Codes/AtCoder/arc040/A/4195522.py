def a_paint(N, S):
    takahashi, aoki = 0, 0
    for row in S:
        for c in row:
            if c == 'R':
                takahashi += 1
            elif c == 'B':
                aoki += 1
    if takahashi > aoki:
        ans = 'TAKAHASHI'
    elif takahashi == aoki:
        ans = 'DRAW'
    else:
        ans = 'AOKI'
    return ans

N = int(input())
S = [input() for _ in [0] * N]
print(a_paint(N, S))