#!/usr/bin/env python3

def construct(N):
    for n in range(40, -1, -1):
        if N >= (1 << n) - 1:
            break
    p = []
    for i in range(1, n+1):
        p.append(i)
    N -= (1 << n) - 1
    for i in range(n-1, -1, -1):
        if N < 1 << i:
            continue
        n += 1
        p = p[:i] + [n] + p[i:]
        N -= 1 << i
    return p

N = int(input())
part = construct(N)
ans = part + [x + 1 for x in range(len(part))]
print(len(ans))
print(*ans, end=' ')
print()