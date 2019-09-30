def is_even(num):
    return num % 2 == 0
def goback(M, x, Sx):
    k = M // 2
    if M == 0:
        return L - x[0]
    elif M == 1:
        return 2 * (L - x[1]) + x[0]
    elif is_even(M):
        return 2 * Sx[k - 1] - 2 * (Sx[M] - Sx[M - k]) - x[M - k] + L * (2 * k + 1)
    else:
        return 2 * Sx[k - 1] + x[k] - 2 * (Sx[M] - Sx[M - k - 1]) + L * 2 * (k + 1)

L, N = (int(i) for i in input().split())
ans = 0

pl = []
for i in range(N):
    pl.append(int(input()))
sumpl = [pl[0]]
for i in range(1, N):
    sumpl.append(sumpl[i - 1] + pl[i])
for i in range(0, N):
    ans = max(ans, goback(i, pl, sumpl))

revpl = [L - p for p in pl[::-1]]
sumrevpl = [revpl[0]]
for i in range(1, N):
    sumrevpl.append(sumrevpl[i - 1] + revpl[i])
for i in range(0, N):
    ans = max(ans, goback(i, revpl, sumrevpl))

print(ans)