# coding: utf-8 -*-

N, M, X, Y = map(int, input().split())

a = list(map(int, input().split()))
b = list(map(int, input().split()))

# print(X, a)

x_max = max(a)
y_min = min(b)


# print(x_max, y_min)

count = 'War'


for i in range(X, Y + 1):
    if i > x_max and i <= y_min and i > X and i < Y:
        count = 'No War'

print(count)