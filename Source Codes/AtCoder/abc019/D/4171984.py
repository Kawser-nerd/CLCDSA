ask = lambda a, b: int(input("? {} {}\n".format(a, b)))
n = int(input())
m1 = max(range(2, n + 1), key=lambda i: ask(1, i))
print("!", max(ask(m1, i) for i in range(1, n + 1) if i != m1))