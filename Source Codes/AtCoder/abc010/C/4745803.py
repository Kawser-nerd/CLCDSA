tx_a, ty_a, tx_b, ty_b, T, V = map(int, input().split())
n = int(input())
flag = False
for _ in range(n):
    x, y = map(int, input().split())
    if ((x - tx_a) ** 2 + (y - ty_a) ** 2) ** (1 / 2) + ((tx_b - x) ** 2 + (ty_b - y) ** 2) ** (1 / 2) <= T * V:
        flag = True
print('YES' if flag else 'NO')