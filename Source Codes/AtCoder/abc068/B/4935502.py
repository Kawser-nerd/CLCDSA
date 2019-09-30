N=int(input())
print([2**i for i in range(8) if 2**i<=N][-1])