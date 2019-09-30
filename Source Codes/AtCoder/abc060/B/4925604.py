A, B, C = map(int, input().split())
flg = 0
for i in range(A, A*B+1):
    if i % A == 0 and i % B == C:
        flg = 1
        break
print('YES') if flg == 1 else print('NO')