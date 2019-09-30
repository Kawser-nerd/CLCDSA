N, M = list(map(int, input().split()))

def solution():
    if M-N < M//N:
        for n in range(N, M+1):
            if M%n==0:
                return M//n
    else:
        for m in range(M//N, 0, -1):
            if M%m==0:
                return m

print(solution())