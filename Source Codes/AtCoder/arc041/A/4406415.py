x, y = map(int, input().split())
k = int(input())

if y >= k:
    print(x + k)
else:
    print(y + x - (k - y))