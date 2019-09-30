N,M = map(int,input().split())

p = 2**M
ans = p * (1900*M + 100*(N-M))
print(ans)