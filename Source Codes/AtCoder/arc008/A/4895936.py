N = int(input())
print(100 * (N // 10) + min(100, N % 10 * 15))