n, k = [int(item) for item in input().split()]
ls = sorted([int(item) for item in input().split()], reverse=True)
print(sum(ls[:k]))