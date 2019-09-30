n, k = list(map(int, input().split()))
ds = set(input().split())

for ans in range(n, 100000):
    if len(set(str(ans)) & ds) == 0:
        break

print(ans)