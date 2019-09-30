def atcoder_express(N: int, T: list, V: list)->float:
    MAXT = sum(T)
    graph = [0] * (2*MAXT + 1)

    T = [0, 0] + T + [0]
    for i in range(N+2):
        T[i+1] += T[i]

    V = [0] + V + [0]

    conditions = []
    for i in range(N+2):
        v, l, r = V[i], T[i], T[i+1]
        conditions.append((l, r, v))

    total = 0.0
    prev_v = 0.0
    for t in range(MAXT*2+1):
        min_v = float('inf')
        x = t / 2
        for l, r, v in conditions:
            if x < l:
                min_v = min(min_v, v + (l - x))
            elif r < x:
                min_v = min(min_v, v + (x - r))
            else:
                min_v = min(min_v, v)
        total += (prev_v + min_v) * 0.5 / 2
        prev_v = min_v

    return total


if __name__ == "__main__":
    N = int(input())
    T = [int(s) for s in input().split()]
    V = [int(s) for s in input().split()]
    ans = atcoder_express(N, T, V)
    print(ans)