def _3():
    from collections import defaultdict

    def can_pair(s1, s2):
        l = []
        for c1, c2 in zip(s1, s2):
            c = sorted([c1, c2])
            if c in l:
                l.remove(c)
            else:
                l.append(c)

        if len(s1) % 2 == 0:
            return len(l) == 0
        else:
            if len(l) == 1:
                if l[0][0] == l[0][1]:
                    return True
            return False

    def pair_graph(s1, s2):
        N = len(s1)
        G = np.zeros([N, N])
        for i in range(N):
            for j in range(i+1, N):
                if s1[i] == s2[j] and s1[j] == s2[i]:
                    G[i, j] = 1
                    G[j, i] = 1
        return G

    import numpy as np
    H, W = list(map(int, input().split(' ')))
    S = []
    d = defaultdict(list)

    for h in range(H):
        s = input()
        S.append(s)
        d[''.join(sorted(S))].append(h)

    already_paired = np.zeros(H)

    Gs = []

    for i in range(H):
        if already_paired[i]:
            continue

        for j in range(i+1, H):
            if already_paired[j]:
                continue

            if can_pair(S[i], S[j]):
                already_paired[i] = 1
                already_paired[j] = 1
                G = pair_graph(S[i], S[j])
                Gs.append(G)
                break

    if already_paired.sum() < H - 1:
        print('NO')
        exit()

    elif already_paired.sum() == H - 1:
        for i in range(H):
            if already_paired[i] == 0:
                G = pair_graph(S[i], S[i])
                Gs.append(G)
                break

    G = np.array(Gs).sum(axis=0) // len(Gs)

    def is_perfect_matching(G):
        N = len(G)
        if N == 1:
            return True

        for i in range(N):
            for j in range(i+1, N):
                if G[i, j] == 1:
                    l = list(range(N))
                    l.remove(i)
                    l.remove(j)
                    if len(l) == 0:
                        return True
                    if is_perfect_matching(G[l][:, l]):
                        return True
        return False

    if is_perfect_matching(G):
        print('YES')
    else:
        print('NO')

if __name__ == '__main__':
    _3()