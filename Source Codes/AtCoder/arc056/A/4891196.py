A, B, K, L = map(int, input().split())

mikan_cost_a = B*(K//L) + A*(K%L)
mikan_cost_b = B*(K//L + 1)

mikan_cost = min(mikan_cost_a, mikan_cost_b)

print(mikan_cost)