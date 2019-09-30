N = int(input())

As = list(map(int,input().split()))

counter = 0
for i in range(0,N):
    while As[i] % 2 == 0:
        As[i] /= 2
        counter += 1

print(counter)