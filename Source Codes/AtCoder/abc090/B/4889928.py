A, B = map(int, input().split())

ans = 0
for i in range(A, B+1):
    if str(i) == str(i)[::-1]:
        ans += 1

print(ans)