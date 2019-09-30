X, Y = map(int, input().split())
N = int(input())
tickets = sorted([tuple(map(int, input().split())) for _ in [0]*N], reverse=True)
b = (X+Y+1)
max_n = b*X + X+Y
dp = [0]*(max_n + 1)
dp_set = set()
add = dp_set.add
add(max_n)

for t, h in tickets:
    for n in sorted(dp_set):
        x, y = divmod(n, b)
        if x > 0 and y >= t:
            newn = (x-1)*b + y-t
            newv = dp[n] + h
            if newv > dp[newn]:
                dp[newn] = newv
                if x > 1 and y > t:
                    add(newn)

print(max(dp))