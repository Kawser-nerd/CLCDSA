N, M = map(int, input().split())
a = [input() for _ in range(N)]
b = [input() for _ in range(M)]
for i in range(N - M + 1):
    for j in range(N - M + 1):
        for k in range(M):
            for l in range(M):
                if a[i + k][j + l] != b[k][l]:
                    break
            else:
                continue
            break
        else:
            print('Yes')
            exit()
print('No')