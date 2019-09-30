n = int(input())
a = [int(input()) for _ in range(n)]

a = list(set(a))

a.sort(reverse=True)

print(a[1])