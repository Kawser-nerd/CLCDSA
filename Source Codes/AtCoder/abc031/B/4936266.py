l,h = map(int, input().split())
a = [int(input()) for _ in range(int(input()))]
for i in range(len(a)):
    if a[i] > h:
        print(-1)
    else:
        print(max(0, l-a[i]))