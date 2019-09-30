def inpl(): return [int(i) for i in input().split()]

N = int(input())
a = inpl()
a1 = a
c = []
while c != a:
    c = a
    b = [i // N for i in a]
    B = sum(b)
    a = [i % N + B - i // N for i in a]
print(sum(a1)-sum(c))