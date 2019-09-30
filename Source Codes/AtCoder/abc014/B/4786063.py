n, X = map(int, input().split())
a = list(map(int, input().split()))
bX = bin(X)[2:]
bX = '0'*(n - len(bX)) + bX
print(sum([e for e, _ in zip(reversed(a), list(bX)) if _ == '1']))