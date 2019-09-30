A, B = map(int, input().split())
res = 0
res = A + B
res = max(res, A * B)
res = max(res, A - B)
print(res)