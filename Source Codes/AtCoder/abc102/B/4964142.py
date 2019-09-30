n = int(input())
a = sorted(list(map(int, input().split())))

print(abs(a[n-1] - a[0]) if len(a) >= 2 else 0)