# -*- coding: utf-8 -*-

def solve():
    N, M = map(int, input().split())
    F = [list() for _ in range(N+1)]
    D = [int() for _ in range(N+1)]
    for _ in range(M):
        a, b = map(int, input().split())
        D[a] += 1
        D[b] += 1
        F[a].append(b)
        F[b].append(a)

    E = [0 for _ in range(7)]
    X = list()
    for a,d in enumerate(D[1:], start=1):
        if d%2==0:
            if d >= 6:
                E[6] += 1
            elif d == 4:
                E[4] += 1
                X.append(a)
            else:
                E[d] += 1
        else:
            return 'No'
            E[1] += 1

    if E[6]>0 or E[4]>2:
        return 'Yes'

    elif E[4]<2:
        return 'No'

    else:
        x, y = X
        q = set((y,))
        R = set((x,))
        while q:
            z = q.pop()
            R.add(z)
            q |= set(F[z])-R
        if set(F[x])&R == set(F[x]):
            return 'No'
        else:
            return 'Yes'

if __name__ == '__main__':
    print(solve())