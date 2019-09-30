n = int(input())
an = list(map(int, input().split()))
sa = sorted(((a, i) for i, a in enumerate(an)), reverse=True)
sa.append((0, 0))

result = [0] * n
prev_a, min_i = sa[0]
for j, (a, i) in enumerate(sa[1:]):
    result[min_i] += (j + 1) * (prev_a - a)
    min_i = min(min_i, i)
    prev_a = a

for cnt in result:
    print(cnt)