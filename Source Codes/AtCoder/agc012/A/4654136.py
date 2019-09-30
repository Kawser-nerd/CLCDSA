n = int(input())
l = sorted(list(map(int, input().split())))
print(sum(l[n::2]))