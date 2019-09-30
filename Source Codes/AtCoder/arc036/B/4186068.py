def b_mountain(N, H):
    ans = 0
    for t in range(N):
        # t??????????????????????????
        if t == 0 or t == N - 1 or H[t - 1] < H[t] > H[t + 1]:
            # ??????????s, t???????
            s, u = t, t
            for i in range(t, -1, -1):
                s = i
                if i >= 1 and H[i - 1] > H[i]:
                    break
            for i in range(t, N):
                u = i
                if i + 1 < N and H[i] < H[i + 1]:
                    break
            ans = max(ans, u - s + 1)  # ????????????
    return ans

N = int(input())
H = [int(input()) for _ in [0] * N]
print(b_mountain(N, H))