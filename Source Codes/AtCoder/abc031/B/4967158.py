l,h = map(int,input().split())
n = int(input())
a = [int(input()) for _ in range(n)]

for i in range(len(a)):
    if a[i] >= l and a[i] <= h:
        print(0)
    elif a[i] > l:
        print(-1)
    else:
        print(l-a[i])