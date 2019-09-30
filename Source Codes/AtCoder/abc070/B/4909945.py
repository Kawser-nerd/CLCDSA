A, B, C, D = map(int, input().split(' '))
start = 0
end = 0

if B <= C or D <= A:
    print(0)
    exit()

if A < C:
    start = C
else:
    start = A

if B < D:
    end = B
else:
    end = D

print(end - start)