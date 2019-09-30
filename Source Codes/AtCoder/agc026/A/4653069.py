N = int(input())
A = list(map(int,input().split()))

ans = 0
changed = False
for a,b in zip(A,A[1:]):
    if changed:
        changed = False
        continue
    if a == b:
        ans += 1
        changed = True
print(ans)