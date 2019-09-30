import math

n = int(input())
r_lst = sorted([int(input()) for _ in range(n)], reverse=True)
ans = 0

for i, r in enumerate(r_lst):
    area = r * r * math.pi

    if i % 2 == 0:
        ans += area
    else:
        ans -= area

print(ans)