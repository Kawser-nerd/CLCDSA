N, M = list(map(int, input().split()))

def solution():
    answer = 1
    for i in range(1, int(M**0.5)+1):
        if M%i ==0:
            if M//i>=N:
                answer = max(answer , i)
            if i>=N:
                answer = max(answer, M//i)
    return answer

print(solution())