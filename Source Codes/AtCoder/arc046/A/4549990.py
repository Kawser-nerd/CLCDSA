N = int(input())

print('9' * (N // 9) if N % 9 == 0 else str(N % 9) * (N // 9 + 1))