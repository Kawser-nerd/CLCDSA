n = int(input())
a = list(map(int, input().split()))
a.sort()
print(sum(a[n::2]))