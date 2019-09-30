N = int(input())
D, X = map(int, input().split())
choco = 0
for i in range(N):
    A = int(input())
    for j in range(101):
        if 1 + j * A <= D:
            choco += 1
        else:
            break
print(choco + X)