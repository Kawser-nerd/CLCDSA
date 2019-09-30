N = int(input())

ans = 0
A_set = set()
for i in range(N):
    A = int(input())
    if A in A_set:
        ans += 1
    A_set |= {A}

print(ans)