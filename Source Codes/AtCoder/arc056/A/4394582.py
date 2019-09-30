A, B, K, L = map(int, input().split())

tmp = (K // L) * B #??

res = min((K - (K // L) * L) * A + tmp, tmp + B)

print(res)