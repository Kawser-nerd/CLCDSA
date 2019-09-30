N, L = map(int, input().split())
S = [str(_) for _ in input()]
cnt = 1
res = 0

for i in S:
    if i == '+':
        cnt += 1
    else:
        cnt -= 1

    if cnt > L:
        res += 1
        cnt = 1

print(res)