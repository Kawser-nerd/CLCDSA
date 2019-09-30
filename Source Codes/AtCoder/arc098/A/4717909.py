""" AtCoder """

N = int(input())
S = input()

e = S.count('E')
w = 0
ans = e

for s in S:
    ans = min(ans, w + e)
    if s == 'W':
        w += 1
    else:
        e -= 1

ans = min(ans, w + e)

print(ans)