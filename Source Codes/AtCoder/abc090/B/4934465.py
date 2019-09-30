A, B = map(int, input().split())
ans = 0
for i in range(A, B+1):
    i_A = str(i)
    i_B = i_A[::-1]
    if i_A == i_B:
        ans += 1
print(ans)