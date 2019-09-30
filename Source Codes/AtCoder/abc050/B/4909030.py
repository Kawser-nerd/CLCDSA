N = int(input())
T = [int(i) for i in input().split()]
M = int(input())
for i in range(M):
    ans = []
    P, X = map(int, input().split())
    for j in range(N):
        if P == j + 1:
            ans.append(X)
        else:
            ans.append(T[j])
    print(sum(ans))