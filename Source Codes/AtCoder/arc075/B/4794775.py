def solve():
    N, A, B = map(int, input().split())
    h = []
    for _ in range(N):
        h.append(int(input()))
    ans_min = 0
    ans_max = 10 ** 9
    while ans_min + 1 < ans_max:
        ans = (ans_min + ans_max) // 2
        count = 0
        for i in h:
            count += (max(0, i - B * ans) + A - B - 1) // (A - B)
        if count > ans:
            ans_min = ans
        else:
            ans_max = ans
    print(ans_max)
    return
solve()