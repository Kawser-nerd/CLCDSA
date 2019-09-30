from itertools import chain
def I(i):
    return lambda x: x[i]

def flatten(iterable):
    return (inner_item for item in iterable for inner_item in item)

def accumulate(initial, reducer, iterable):
    acc = initial
    yield initial
    for item in iterable:
        acc = reducer(acc, item)
        yield acc




N = int(input())
vs = []
for n in range(N):
    a, b = map(int, input().split())
    vs.append((a, b))

print(max(accumulate(0, lambda x, y: x + y,
    flatten(chain(
        sorted(((a, -b) for a, b in vs if a <= b), key=I(0)),
        sorted(((a, -b) for a, b in vs if a > b), key=I(1)),
    ))
)))