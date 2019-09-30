N = int(input())

result = (N // 10) * 100 + min((N % 10) * 15, 100)

print(result)