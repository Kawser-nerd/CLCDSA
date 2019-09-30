N, K = map(int, input().split())
R = list(map(int, input().split()))
C = 0

R = sorted(R, reverse = True)[0 : K]
R = sorted(R)
for i in range(K):
    C = (C + R[i]) / 2
print(C)