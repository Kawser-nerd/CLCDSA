n = int(input())
t, a = map(int, input().split())
h = list(map(int, input().split()))
ans_l = []

def elev(t, n):
    high = t - n * 0.006
    return abs(a - high)

for i in range(n):
    ans = elev(t, h[i])
    ans_l.append(ans)

num = min(ans_l)
print(ans_l.index(num) + 1)