n = int(input())
s = list(map(int, input().split()))
evens, odds = 0, 0
for i in s:
    if i % 2 == 0:
        evens += 1
    else:
        odds += 1
if odds % 2 == 0:
    ok = True
else:
    ok = False
print('YES' if ok else 'NO')