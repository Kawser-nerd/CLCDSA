N = int(input())
A = list(map(lambda x: x%2, map(int, input().split())))

if A.count(1)%2:
    if A.count(0) > 0:
        print('NO')
    else:
        print('YES')
else:
    print('YES')