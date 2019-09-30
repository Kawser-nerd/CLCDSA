Q, H, S, D = list(map(int, input().split()))
N = int(input())

print(N//2*min(Q*8, H*4, S*2, D) + N%2*min(Q*4, H*2, S))