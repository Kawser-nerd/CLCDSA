# coding: utf-8

N, M, X, Y = map(int, input().split())
x = list(map(int, input().split()))
y = list(map(int, input().split()))

x.append(X)
y.append(Y)

# print(x)
# print(y)

max_x = max(x)
min_y = min(y)

if max_x < min_y:
    print("No War")
else:
    print("War")