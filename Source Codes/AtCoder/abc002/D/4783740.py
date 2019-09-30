import itertools

n, m = [int(x) for x in input().split()]
friends = set(tuple(int(x) for x in input().split()) for _ in range(m))

for chosen in itertools.chain.from_iterable(itertools.combinations(range(1, n + 1), i) for i in range(n, 0, -1)):
    if all(pair in friends for pair in itertools.combinations(chosen, 2)):
        print(len(chosen))
        break