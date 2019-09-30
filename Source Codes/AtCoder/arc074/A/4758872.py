def solve():
    ans = 1000000
    for i in range(2):
        if H[i] % 3 == 0:
            return 0
        ans = min(ans, H[1 - i])
        H1 = H[i] // 3
        S_max = (H1 + 1) * H[1 - i]
        S_min = (H[i] - H1 - 1) * (H[1 - i] // 2)
        ans = min(ans, S_max - S_min)
        S_min = H1 * H[1 - i]
        S_max = (H[i] - H1) * ((H[1 - i] + 1) // 2)
        ans = min(ans, S_max - S_min)
    return ans

H = list(map(int, input().split()))
print(solve())