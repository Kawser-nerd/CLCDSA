n = int(input())


mnsk = []
for i in range(1,n + 1):
    for h in range(1,n + 1):
        if i * h <= n:
            mnsk.append(n - i * h + abs(i - h))
        else:
            break

print(min(mnsk))