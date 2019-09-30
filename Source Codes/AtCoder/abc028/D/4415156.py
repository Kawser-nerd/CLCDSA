N, K = map(int, input().split())
a, b = K-1, N-K
ans = (6*a*b+3*(a+b)+1)/(N**3)
print("{:.15f}".format(ans))