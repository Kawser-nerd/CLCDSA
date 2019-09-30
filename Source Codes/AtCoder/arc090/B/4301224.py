n, m = map(int, input().split())

lrds = [tuple(map(int, input().split())) for _ in range(m)]

xs = [None for _ in range(n)]

ps = [[] for _ in range(n)]

for lrd in lrds:
    l, r, d = lrd
    ps[l-1].append((r-1, d))
    ps[r-1].append((l-1, -d))

not_decided = set(range(n))

def solve():
    while len(not_decided) != 0:
        t = not_decided.pop()
        xs[t] = 0

        stack = [t]
        while len(stack) != 0:
            c = stack.pop()
            for p in ps[c]:
                another, relative_position = p
                if another in not_decided:
                    xs[another] = xs[c] + relative_position
                    not_decided.remove(another)
                    stack.append(another)
                else:
                    if xs[another] != xs[c] + relative_position:
                        return False
    return True

if solve():
    print("Yes")
else:
    print("No")