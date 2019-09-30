N = int(input())
print(min([sum(map(int, list(str(x) + str(N - x)))) for x in range(1, N // 2 + 1)]))