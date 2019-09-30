N, K = [int(x) for x in input().split()]

cA = 1
cB = (N-1)*3
cC = 6*(N-K)*(K-1)
print((cA + cB + cC)/ N**3)