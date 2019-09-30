N = int(input())
a = list(map(int, input().split()))
list.sort(a)
print(sum(a[N::2]))