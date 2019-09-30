import collections

R, C, K = map(int, input().split())
n = int(input())
r_candy = [0] * R
c_candy = [0] * C
candy = []
for i in range(n):
    r, c = map(int, input().split())
    r_candy[r - 1] += 1
    c_candy[c - 1] += 1
    candy.append((r - 1, c - 1))
ans = 0
for i in candy:
    if r_candy[i[0]] + c_candy[i[1]] == K:
        ans -= 1
    elif r_candy[i[0]] + c_candy[i[1]] == K + 1:
        ans += 1
r_candy = collections.Counter(r_candy)
c_candy = collections.Counter(c_candy)
for i in r_candy:
    ans += c_candy[K - i] * r_candy[i]
print(ans)