N = int(input())
T = list(map(int, input().split()))
M = int(input())

for i in range(M):
    T1 = T.copy()
    P, X = map(int, input().split())
    T1[P-1] = X
    print(sum(T1))