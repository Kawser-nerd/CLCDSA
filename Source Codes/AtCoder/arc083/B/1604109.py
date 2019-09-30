N = int(input())
inf = float("inf")
A = [list(map(int, input().split())) for _ in [0]*N]

for i in range(N):
    A[i][i] = inf

result = 0
for i in range(N-1):
    for j, dist in enumerate(A[i][i+1:], start=i+1):
        for _A in A:
            if dist >= _A[i]+_A[j]:
                if dist > _A[i]+_A[j]:
                    print(-1)
                    exit()
                break
        else:
            result += dist

print(result)