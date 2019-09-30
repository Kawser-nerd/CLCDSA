N, K = map(int, input().split())
As = list(map(int, input().split()))

count = 1
N -= K
while N > 0:
    count += 1
    N -= K - 1
print(count)