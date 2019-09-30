n = int(input())
t = [int(i) for i in input().split()]
m = int(input())
for _ in range(m):
    s = sum(t)
    p, x = map(int, input().split())
    print(s - t[p-1] + x)