N = input()
print(max(int(N[0]) - 1 + 9 * (len(N) - 1), sum(list(map(lambda x: int(x), N)))))