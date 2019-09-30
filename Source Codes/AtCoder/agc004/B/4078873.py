N, x = map(int, input().split())
a_list = list(map(int, input().split()))

ans = float("inf")
cost_list = [float("inf") for _ in range(N)]
for i in range(N):
    cost = 0
    for j in range(N):
        if i == 0:
            cost += a_list[j]
            cost_list[j] = a_list[j]
        else:
            tmp = cost_list[j]
            if tmp > a_list[- i + j]:
                cost_list[j] = a_list[- i + j]
                cost += a_list[- i + j]
            else:
                cost += tmp

    cost += x * i
    ans = min(ans, cost)
print(ans)