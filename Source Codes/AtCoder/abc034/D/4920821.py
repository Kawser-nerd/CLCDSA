def salt_solution(N: int, K: int, solutions: list)->float:
    l, r = 0.0, 100.0
    e = 10 ** (-10)

    def check(goal: float)->bool:
        # ??????????
        A = sorted((-w * (p - goal), w, p) for w, p in solutions)
        cw, cp = 0, 0
        for _, w, p in A[:K]:
            cp = (cw*cp + w*p) / (cw + w)
            cw = w + cw

        return cp >= goal

    while r - l > e:
        m = (r+l) / 2
        if check(m):
            l = m
        else:
            r = m
    return l


if __name__ == "__main__":
    N = 0
    N, K = map(int, input().split())
    solutions = [tuple(int(s) for s in input().split()) for _ in range(N)]
    ans = salt_solution(N, K, solutions)
    print(ans)