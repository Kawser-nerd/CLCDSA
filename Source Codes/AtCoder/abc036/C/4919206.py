def seat_pressure(N: int, A: list)->list:
    m = {a: i for i, a in enumerate(sorted(set(A)))}

    # for a in A:
    #     print(d[a])
#     s = set(A)
#     m = {v: i for i, v in enumerate(sorted(set(s)))}
    return [m[a] for a in A]


if __name__ == "__main__":
    N = int(input())
    A = [int(input()) for _ in range(N)]
    ans = seat_pressure(N, A)

    for a in ans:
        print(a)