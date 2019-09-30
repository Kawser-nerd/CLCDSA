N = int(input())
a = list(map(int, input().split()))

if all(i < j for i, j in zip(a, a[1:])):
    print(1)
    exit()

keta_count = 19
a = [10**10]+[v-1 for v in a if v <= keta_count]+[10**10]
a = [-1] + [j for i, j, k in zip(a, a[1:], a[2:]) if not i < j > k]

if len(a) == 1:
    print(2)
    exit()

ok, ng = len(a), 1

while ok-ng > 1:
    mid = (ok+ng) // 2
    keta = [0]*keta_count

    for prev, current in zip(a, a[1:]):
        if prev < current:
            for i in range(current, prev, -1):
                keta[i] = 0
        else:
            kuriage = 0
            for num in keta[prev:current:-1]:
                kuriage = (kuriage + num) // mid
            keta[current] += kuriage + 1

    for i in range(a[-1], 0, -1):
        keta[i-1] += keta[i] // mid
    if keta[0] >= mid:
        ng = mid
    else:
        ok = mid

print(ok)