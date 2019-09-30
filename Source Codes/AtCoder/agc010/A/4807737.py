N = int(input())
list = list(map(int, input().split()))

count = 0
for a in list :
    if a % 2 != 0 :
        count += 1

if count % 2 == 0 :
    print('YES')
else :
    print('NO')