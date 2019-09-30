N = int(input())
L = []
ans = 0
for _ in range(N):
    L.append(int(input()))
for i in range(len(L)):
    # L[i]???
    cnt = 0
    for j in range(len(L)):
        if i != j:
            if L[i] % L[j] == 0:
                cnt += 1
    if cnt % 2 == 1:
        ans += 1/2
    else:
        ans += (cnt+2)/ (2 *cnt+ 2)

print(ans)