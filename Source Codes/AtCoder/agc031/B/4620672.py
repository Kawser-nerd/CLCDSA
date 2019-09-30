N = int(input())
pre_stone = 0
div = 10**9+7
dp = 1
dp_dict = {}
for _ in range(N):
    c = int(input())
    if pre_stone != c:
        pre_stone = c
        if c not in dp_dict:
            dp_dict[c] = 0
        dp += dp_dict[c]
        dp_dict[c] = dp

print(dp%div)