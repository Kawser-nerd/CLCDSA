import sys

input = sys.stdin.readline
a, b, k = map(int, input().split())

if b - a + 1 >= 2 * k:
    for i in range(0, k):
        print(a + i)
    for i in range(k - 1, -1, -1):
        print(b - i)
else:
    for i in range(a, b + 1):
        print(i)