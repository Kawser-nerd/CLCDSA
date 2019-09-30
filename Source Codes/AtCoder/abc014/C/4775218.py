n = int(input())

a = []
b = []

diff = [0 for i in range(1000002)]

for i in range(n):
    _a, _b = map(int, input().split())
    a.append(_a)
    b.append(_b)

    diff[_a] += 1
    diff[_b + 1] -= 1

max_customer = 0
customer = 0

for i in range(1000001):
    if diff[i] != 0:
        customer += diff[i]
        max_customer = max(max_customer, customer)

print(max_customer)