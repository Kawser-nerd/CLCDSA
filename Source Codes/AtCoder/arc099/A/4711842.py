""" AtCoder """

N, K = map(int, input().split())
A = list(map(int, input().split()))

p = K
ans = 1

while True:
    if p >= N:
        break
    p += K - 1
    ans += 1

print(ans)