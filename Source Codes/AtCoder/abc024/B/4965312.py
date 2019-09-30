def autodoor(N: int, T: int, A: list)->int:
    open_time, close_time = 0, 0
    total_opening_time = 0

    for a in A:
        if a > close_time:
            total_opening_time += close_time - open_time
            open_time = a

        close_time = a + T
    else:
        total_opening_time += close_time - open_time

    return total_opening_time


if __name__ == "__main__":
    N = 0
    N, T = map(int, input().split())
    A = [int(input()) for _ in range(N)]
    ans = autodoor(N, T, A)
    print(ans)