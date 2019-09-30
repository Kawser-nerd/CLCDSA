N = int(input())
A = N
for i in range(2, int(pow(N, 0.5)) + 1):
    if N % i == 0:
        A = N / i
for j in range(1, N + 1):
    if A < 10 ** j:
        print(j)
        exit()