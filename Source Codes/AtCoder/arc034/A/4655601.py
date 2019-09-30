N = int(input())
ResMax = 0

for i in range(N):
    p = [int(_) for _ in input().split()]
    tmp = sum(p[:4]) + p[4]*110/900
    if tmp > ResMax:
        ResMax = tmp

print(ResMax)