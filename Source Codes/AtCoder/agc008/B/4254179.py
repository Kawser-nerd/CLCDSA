n, k = map(int, input().split())
a = [int(m) for m in input().split()]
sum = 0
for i in range(n):
    if a[i] > 0:
        sum += a[i]

sei = 0
fu = 0
for i in range(k):
    if a[i] > 0:
        sei += a[i]
    else:
        fu += a[i]
zen = sei + fu
ansli = []
if zen > 0:
    ansli.append(sum + fu)
else:
    ansli.append(sum - sei)
for i in range(k, n):
    if a[i] > 0:
        sei += a[i]
    else:
        fu += a[i]
    if a[i - k] > 0:
        sei -= a[i - k]
    else:
        fu -= a[i - k]
    zen = sei + fu
    if zen > 0:
        ansli.append(sum + fu)
    else:
        ansli.append(sum - sei)
print(max(ansli))