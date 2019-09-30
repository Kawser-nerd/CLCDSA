_ = input()
a = list(map(int, input().split()))
a.sort(reverse = True)
print(sum(a[::2]))