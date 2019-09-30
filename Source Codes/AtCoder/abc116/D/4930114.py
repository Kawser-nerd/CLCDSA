import heapq

INF = float('inf')
n, k = map(int, input().split())
sushi = {}

for _ in range(n):
    t, d = map(int, input().split())
    if t not in sushi:
        sushi[t] = []
    sushi[t].append(d)

for s in sushi.values():
    s.sort(reverse=True)

eat_counts = {s: 0 for s in sushi.keys()}

# ?????????
news = []
# ????
repeats = []
# ?????
eats = []

# ????????????? heap ?
for name, deli_li in sushi.items():
    # (-????, name)
    heapq.heappush(news, (-deli_li[0], name))

sum_deli = 0
variety = 0

for _ in range(k):
    # ???????????
    if news and (not repeats or news[0] <= repeats[0]):
        deli, name = heapq.heappop(news)
        variety += 1
    else:
        deli, name = heapq.heappop(repeats)

    sum_deli += -deli
    eat_counts[name] += 1
    heapq.heappush(eats, (-deli, name))
    if eat_counts[name] < len(sushi[name]):
        heapq.heappush(repeats, (-sushi[name][eat_counts[name]], name))

# ?????????????
# ????????????????????
ans = sum_deli + variety ** 2
while True:
    if not news or not eats:
        break

    # ??????????????????????
    ate_min_deli, ate_min_name = heapq.heappop(eats)
    eat_counts[ate_min_name] -= 1
    if eat_counts[ate_min_name] <= 0:
        # ??????????????
        continue

    sum_deli -= ate_min_deli

    deli, name = heapq.heappop(news)
    variety += 1
    sum_deli += -deli
    eat_counts[name] += 1

    ans = max(ans, sum_deli + variety ** 2)

print(ans)