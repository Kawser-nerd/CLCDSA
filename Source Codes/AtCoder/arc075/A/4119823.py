N = int(input())
s = []
for _ in range(N):
    s.append(int(input()))

s = sorted(s)
sum_point = sum(s)

s = list(filter(lambda x: x % 10 != 0, s))


if sum_point % 10 != 0:
    ans = sum_point
else:
    if len(s) == 0:
        ans = 0
    else:
        ans = sum_point - s[0]
print(ans)