K = int(input())
gu = 0
ki = 0

for i in range(K):
    if i % 2 == 0:
        gu += 1
    else:
        ki += 1

print(ki * gu)