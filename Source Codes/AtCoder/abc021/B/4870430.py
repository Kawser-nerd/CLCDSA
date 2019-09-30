N = int(input())
a, b = map(int, input().split())
K = int(input())
P = [int(i) for i in input().split()]
P += a, b
if len(set(P)) == K + 2:
    print('YES')
else:
    print('NO')