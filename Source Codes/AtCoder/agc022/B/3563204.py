N = int(input())

if N == 3:
    print(2, 5, 63)
    exit()

count = 20000
m2 = list(i for i in range(2, 30001, 2) if i % 6 != 0)
m3 = list(i for i in range(3, 30001, 3) if i % 6 != 0)
m6 = list(range(6, 30001, 6))

if count > N:
    diff = min(count-N, 9998)
    if diff % 2 == 1:
        diff -= 1
    if diff:
        m2 = m2[:-diff]
    count -= diff
if count > N:
    diff = min(count-N, 4998)
    if diff % 2 == 1:
        diff -= 1
    if diff:
        m3 = m3[:-diff]
    count -= diff
if count > N:
    diff = count-N
    count -= diff
    if diff:
        m6 = m6[:-diff]

ans = m2+m3+m6
print(" ".join(map(str, ans)))