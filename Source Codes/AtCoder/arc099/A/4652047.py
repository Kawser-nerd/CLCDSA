N, K = map(int, input().split())
_ = input()
print((N-1)//(K-1) + ((N-1)%(K-1) > 0))