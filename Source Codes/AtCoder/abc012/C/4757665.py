N = int(input())
ans = []

for i in range(1, 2026-N):
    if i >= 10:
        break
    if (2025-N)%i == 0 and (2025-N)//i < 10:
        ans.append(str(i)+' x '+str((2025-N)//i))
print(*ans, sep='\n')