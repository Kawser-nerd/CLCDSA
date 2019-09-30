from math import pi


def N_heavy_round(N: int, R: list) -> float:
    R.sort(key=lambda x: - x)
    S = 0
    for i, r in enumerate(R):
        if i % 2 == 0:
            S += r * r
        else:
            S -= r * r
    return S * pi


if __name__ == "__main__":
    N = int(input())
    R = [int(input()) for _ in range(N)]
    ans = N_heavy_round(N, R)
    print(ans)