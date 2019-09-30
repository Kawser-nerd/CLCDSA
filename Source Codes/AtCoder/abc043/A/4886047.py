def children_and_candies(N: int)->int:
    return N * (N + 1) // 2


if __name__ == "__main__":
    N = int(input())
    ans = children_and_candies(N)
    print(ans)