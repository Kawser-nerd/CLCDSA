n = int(input())
k = int(input())
ans = 1
for i in range(n):
    ope_A = ans * 2
    ope_B = ans + k
    ans = min(ope_A, ope_B)
print(ans)