N = int(input())
min_sum = 9 * 10
for x in range(1, N // 2 + 1):
    min_sum = min(min_sum, sum(map(int, list(str(x) + str(N - x)))))
print(min_sum)