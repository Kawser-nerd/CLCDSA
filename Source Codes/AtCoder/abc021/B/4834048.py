N = int(input())
a, b = map(int, input().split())
K = int(input())
P = list(map(int, input().split()))

if len(set(P + [a] + [b])) == K+2:
    print('YES')
else:
    print('NO')