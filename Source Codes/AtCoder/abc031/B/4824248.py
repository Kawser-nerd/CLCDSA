l, h = map(int, input().split())
n = int(input())
for _ in range(n):
    a = int(input())
    if a < l:
        print(l-a)
    elif a <= h:
        print(0)
    else:
        print(-1)