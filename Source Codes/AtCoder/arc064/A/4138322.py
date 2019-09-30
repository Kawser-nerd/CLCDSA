n, x = map(int, input().split())
l = list(map(int, input().split()))
total = 0

for i in range(n - 1):
    diff = l[i] + l[i+1] - x
    if diff > 0:
        total += diff
        if diff > l[i+1]:
            l[i+1]=0
        else:
            l[i+1] -= diff

print(total)