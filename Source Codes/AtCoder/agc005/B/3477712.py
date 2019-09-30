N = int(input())
As = list(map(int, input().split()))

iAs = [0] * (N + 1)
for i, A in enumerate(As):
    iAs[A] = i

ans = 0
iLs = list(range(N + 1))
iRs = list(range(N + 1))
for A in reversed(range(1, N + 1)):
    iA = iAs[A]
    iL, iR = iLs[iA], iRs[iA]
    ans += A * (iA - iL + 1) * (iR - iA + 1)
    iLs[iR + 1] = iL
    iRs[iL - 1] = iR

print(ans)