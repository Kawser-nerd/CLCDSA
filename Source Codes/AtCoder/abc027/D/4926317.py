def robot(S: str) -> int:
    # Sp[i], Sm[i] ????? i ????? + / - ???????
    N = len(S)
    Sp, Sm = [0] * (N + 1), [0] * (N + 1)
    A = [float('inf')] * (N + 1)

    S = reversed(S)

    M = 0
    for i, c in enumerate(S):
        Sp[i + 1], Sm[i + 1] = Sp[i], Sm[i]
        if c == 'M':
            M += 1
            A[i + 1] = Sp[i] - Sm[i]
        elif c == '+':
            Sp[i + 1] += 1
        else:  # c == '-'
            Sm[i + 1] += 1

    A.sort()

    return sum(A[M//2:M]) - sum(A[:M//2])


if __name__ == "__main__":
    S = input()
    ans = robot(S)
    print(ans)