def pilot(N: int, M: int, X: int, Y: int, A: list, B: list) -> int:
    ai, bi = 0, 0
    t = 0
    repeat = 0
    while ai < N and bi < M:
        # A -> B
        while ai < N and A[ai] < t:
            ai += 1

        if N <= ai:
            break

        t = A[ai] + X
        ai += 1

        # B -> A
        while bi < M and B[bi] < t:
            bi += 1

        if M <= bi:
            break

        t = B[bi] + Y
        bi += 1
        repeat += 1

    return repeat


if __name__ == "__main__":
    N, M = map(int, input().split())
    X, Y = map(int, input().split())
    A = [int(s) for s in input().split()]
    B = [int(s) for s in input().split()]

    ans = pilot(N, M, X, Y, A, B)
    print(ans)