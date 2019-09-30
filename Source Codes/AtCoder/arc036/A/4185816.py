def a_good_sleep(N, K, T):
    sleep_time = sum(T[:3])
    if sleep_time < K:
        return 3

    ans = -1
    for day, t in enumerate(T[3:], 4):
        sleep_time -= T[day - 3 - 1]
        sleep_time += T[day - 1]
        if sleep_time < K:
            ans = day
            break
    return ans

N, K = [int(i) for i in input().split()]
T = [int(input()) for _ in [0] * N]
print(a_good_sleep(N, K, T))