A, B = map(int, input().split())
ans = 0
S = [list(str(i)) for i in range(A, B + 1)]
for i in S:
    if (i == i[::-1]):
        ans += 1
print(ans)