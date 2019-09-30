S = input()
N = int(input())

S = sorted(S)
cnt = 0
for s in S:
    for t in S:
        cnt += 1
        ans = s+t
        if cnt == N:
            break
    if cnt == N:
        break

print(ans)