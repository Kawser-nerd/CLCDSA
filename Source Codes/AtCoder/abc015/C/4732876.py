def exec(x, layer = 0, targets = []):
    # ?????
    if layer == len(x):
        xor = 0
        for num in targets:
            xor = xor ^ num
        return xor == 0
    else:
        for num in x[layer]:
            targets2 = targets.copy()
            targets2.append(num)
            result = exec(x, layer + 1, targets2)
            if result:
                return True

n, k = map(int, input().split())
x = []
for i in range(n):
    x.append(list(map(int, input().split())))
result = exec(x, 0, targets = [])
print("Found" if result else "Nothing")