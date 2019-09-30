from bisect import bisect_right


N, C, K = map(int, input().split())
t = [int(input()) for _ in range(N)]
t = list(sorted(t))

ans = 0
idx = 0
while idx < N:
    in_time_idx = bisect_right(t, t[idx] + K)
    if (in_time_idx - 1) - idx + 1 <= C:
        idx = in_time_idx
    else:
        idx += C
    ans += 1
print(ans)