# DP

def dp_post(n, lst):
    lst_cost = [0] * n
    lst_cost[1] = abs(lst[0] - lst[1])
    for i in range(2, N):
        lst_cost[i] = min(
            lst_cost[i-2] + abs(lst[i-2] - lst[i]),
            lst_cost[i-1] + abs(lst[i-1] - lst[i])
            )
    return lst_cost


N = int(input())
lst_a = list(map(int, input().split()))

ans = dp_post(N, lst_a)[N - 1]
print(ans)