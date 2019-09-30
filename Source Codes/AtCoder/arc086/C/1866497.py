from collections import deque


def get_pow():
    cache = {}

    def func(x):
        if x not in cache:
            cache[x] = pow(2, x, mod)
        return cache[x]

    return func


mod = 1000000007
n = int(input())
parents = list(map(int, input().split()))
children = [set() for _ in range(n + 1)]
for c, p in enumerate(parents):
    children[p].add(c + 1)

levels = [{0}]
while True:
    level = set()
    for p in levels[-1]:
        level.update(children[p])
    if not level:
        break
    levels.append(level)
levels.reverse()

level_node_count = []
balls = [None] * (n + 1)

for i, level in enumerate(levels):
    level_node_count.append(len(level))
    for node in level:
        cn = children[node]
        if cn:
            if len(cn) == 1:
                bs = balls[cn.pop()]
                bs.appendleft([1, 1, 0])
                balls[node] = bs
                continue
            balls_from_children = [balls[c] for c in children[node]]
            balls_from_children.sort(key=len)
            bs1 = balls_from_children[0]
            for bs2 in balls_from_children[1:]:
                for (b10, b11, b12), b2 in zip(bs1, bs2):
                    b2[2] = ((b11 + b12) * b2[1] + b12 * b2[0]) % mod
                    b2[1] = (b10 * b2[1] + b11 * b2[0]) % mod
                    b2[0] = b2[0] * b10 % mod
                bs1 = bs2
            for b in bs1:
                b[0] = (b[0] + b[2]) % mod
                b[2] = 0
            bs1.appendleft([1, 1, 0])
            balls[node] = bs1
        else:
            balls[node] = deque([[1, 1, 0]])

level_node_count.reverse()

pow2 = get_pow()
print(sum(b[1] * pow2(n - l + 1) % mod for l, b in zip(level_node_count, balls[0])) % mod)