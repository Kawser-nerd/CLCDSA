N = int(input())
As = map(int, input().split())

count = 0
for A in As:
    if A % 2 == 1:
        count += 1

if count % 2 == 1:
    print('NO')
else:
    print('YES')