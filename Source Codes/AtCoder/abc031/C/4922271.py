def seq_game(N: int, A: list) -> int:
    Tmax = -float('inf')
    for ti in range(N):
        # ??????????????????????????
        # ???
        Amax = -float('inf')
        Aidx = -1

        for ai in range(N):
            if ti == ai:
                continue

            if ti < ai:
                ap = sum(A[ti + 1:ai + 1:2])
            else:
                ap = sum(A[ai + 1:ti + 1:2])

            if Amax < ap:
                Amax = ap
                Aidx = ai

        if ti < Aidx:
            Tmax = max(Tmax, sum(A[ti:Aidx + 1:2]))
        else:
            Tmax = max(Tmax, sum(A[Aidx:ti + 1:2]))

    return Tmax


if __name__ == "__main__":
    N = int(input())
    A = [int(s) for s in input().split()]
    ans = seq_game(N, A)
    print(ans)