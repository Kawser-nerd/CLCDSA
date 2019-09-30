def simple_incremental(N: int, A: list)->int:
    l, r = 0, 0
    count = 0
    while r < N:
        while r + 1 < N and A[r] < A[r+1]:
            r = r + 1

        count += (r-l+1) * (r-l+2) // 2

        l = r = r + 1

    return count


if __name__ == "__main__":
    N = int(input())
    A = [int(s) for s in input().split()]
    ans = simple_incremental(N, A)
    print(ans)