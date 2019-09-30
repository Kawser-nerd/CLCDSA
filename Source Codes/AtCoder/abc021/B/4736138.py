N = int(input())
a, b = map(int, input().split())
K = int(input())
P = list(map(int, input().split()))
if a in P or b in P:
    print('NO')
    exit()
if len(set(P)) == len(P):
    print('YES')
else:
    print('NO')