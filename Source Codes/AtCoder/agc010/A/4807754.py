N = int(input())
list = list(map(int, input().split()))

if sum(list) % 2 == 0 :
    print('YES')
else :
    print('NO')