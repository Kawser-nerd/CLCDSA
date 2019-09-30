W = int(input())
N, K = map(int, input().split())
in_list = []
for i in range(N):
    a, b = map(int, input().split())
    in_list.append([a, b])
in_list = sorted(in_list, reverse=True)
memo = {}

def dfs(use_w, use_num, now):
    if now < 0:
        return 0
    l = in_list[now]
    a, b = l[0], l[1]
    use_num = min(use_num, now+1)
    if use_num < 1:
        return 0
    if (now, use_num, use_w) in memo:
        return memo[now, use_num, use_w]

    memo[now, use_num, use_w] = max(dfs(use_w - a, use_num - 1, now - 1) + (b if use_w-a >=0 else 0),
                                    dfs(use_w, use_num, now - 1))
    return memo[now, use_num, use_w]


result = dfs(W, K, N-1)
print(result)