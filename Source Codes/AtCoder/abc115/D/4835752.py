N, X = map(int, input().split())
maisuu = [1]
patimaisuu = [1]
for i in range(1,N + 1):
    maisuu.append(2 * maisuu[i - 1] + 3)
    patimaisuu.append(2 * patimaisuu[i - 1] + 1)

def pati(l, n):
    if n == 0:
        return 0
    elif l == 0:
        return 1
    elif n == 1:
        return 0
    elif 2 <= n <= maisuu[l] // 2:
        return pati(l - 1, n - 1)
    else:
        return pati(l - 1, n - maisuu[l - 1] - 2) + 1 + patimaisuu[l - 1]

print(pati(N, X))