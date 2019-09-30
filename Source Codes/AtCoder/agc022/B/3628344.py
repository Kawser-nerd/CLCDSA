N = int(input())

if N == 3:
    ans = [2, 3, 25]
else:
    # [???6???]?????????????
    if N % 2 == 0:
        As = [2, 10, 3, 9, 4, 8, 6, 12]
    else:
        As = [6, 2, 10, 3, 9, 4, 8, 12]

    ans = []
    for i in range(N):
        ans.append(As[i % 8] + 12 * (i // 8))

print(' '.join(map(str, ans)))