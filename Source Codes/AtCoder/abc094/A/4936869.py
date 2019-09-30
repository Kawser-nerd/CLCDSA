A, B, X = map(int, input().split())
if X <= A+B and X >= A:
    print('YES')
else:
    print('NO')