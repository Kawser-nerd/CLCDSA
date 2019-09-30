N, x = map(int, input().split())
a_list = list(map(int, input().split()))
ex_list = a_list.copy()
ex_list.extend(a_list)

ans = float("inf")
cost_list = [float("inf") for _ in range(N)]
for i in range(N):
    cost = 0
    for j in range(N):
        if i == 0:
            cost += ex_list[N + j]
            cost_list[j] = ex_list[N + j]
        else:
            tmp = cost_list[j]
            if tmp > ex_list[N - i + j]:
                cost_list[j] = ex_list[N - i + j]
                cost += ex_list[N - i + j]
            else:
                cost += tmp

    cost += x * i
    ans = min(ans, cost)
print(ans)