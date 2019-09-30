def painting_balls_with_atcodeer(N: int, K: int) -> int:
    return K * ((K-1) ** (N-1))


if __name__ == "__main__":
    N, K = map(int, input().split())
    ans = painting_balls_with_atcodeer(N, K)
    print(ans)