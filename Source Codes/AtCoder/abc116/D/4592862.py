N, K = [int(_) for _ in input().split()]
t_and_d = [[int(_) for _ in input().split()] for _ in range(N)]
t_and_d.sort(key=lambda x: x[1], reverse=True)

over_stock = []
type_set = set()

for t_i, d_i in t_and_d[:K]:
    if t_i in type_set:
        over_stock += [d_i]
    else:
        type_set.add(t_i)

x = len(type_set)
point = sum([d for t, d in t_and_d[:K]]) + x ** 2
point_max = point

for t_i, d_i in t_and_d[K:]:
    if over_stock:
        if t_i in type_set:
            continue
        else:
            diff = (x + 1) ** 2 - x ** 2 + d_i - over_stock.pop()
            type_set.add(t_i)
            x += 1
            point += diff
            point_max = max(point_max, point)

print(point_max)