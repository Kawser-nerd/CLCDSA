from sys import stdin
input = stdin.readline

n, m, a, b = map(int, input().split())

for i in range(1, m+1):
    c = int(input())
    if n <= a:
        n += b
    n -= c
    if n < 0:
        print(i)
        break
else:
    print("complete")