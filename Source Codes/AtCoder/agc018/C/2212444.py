from heapq import heapify, heappushpop
from itertools import accumulate

x, y, z = map(int, input().split())
persons = [list(map(int, input().split())) for _ in range(x + y + z)]
persons.sort(key=lambda abc: abc[0] - abc[1])

ans_g = sum(x[0] for x in persons[-x:])
ans_s = sum(x[1] for x in persons[:y])
ans_c = sum(x[2] for x in persons[y:-x])

gold_pq = [a - c for a, b, c in persons[-x:]]
silver_pq = [b - c for a, b, c in persons[:y]]
heapify(gold_pq)
heapify(silver_pq)

ans_f = [0]
for a, b, c in persons[y:-x]:
    np = b - c
    rp = heappushpop(silver_pq, np)
    ans_f.append(np - rp)

ans_b = [0]
for a, b, c in persons[-x - 1:y - 1:-1]:
    np = a - c
    rp = heappushpop(gold_pq, np)
    ans_b.append(np - rp)

ans_f = list(accumulate(ans_f))
ans_b = list(accumulate(ans_b))
print(ans_g + ans_s + ans_c + max(sum(z) for z in zip(ans_f, reversed(ans_b))))