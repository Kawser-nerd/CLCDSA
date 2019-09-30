N = sorted(list(map(int, input().split())), reverse=True)
print(N[0] * 2**int(input()) + N[1] + N[2])