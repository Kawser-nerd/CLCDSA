A, B = map(list, input().split())

ans = -1000
alt = list(map(str, range(10)))

for i in range(3):
    for item in alt:
        if not (i == 0 and item == '0'):
            copy_A = A[:]
            copy_A[i] = item
            diff = int(''.join(copy_A)) - int(''.join(B))
            ans = max(ans, diff)

for i in range(3):
    for item in alt:
        if not (i == 0 and item == '0'):
            copy_B = B[:]
            copy_B[i] = item
            diff = int(''.join(A)) - int(''.join(copy_B))
            ans = max(ans, diff)

print(ans)