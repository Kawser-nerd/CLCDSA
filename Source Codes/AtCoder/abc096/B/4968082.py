a = list(map(int, input().split()))
k = int(input())
print(sum(a) - max(a) + max(a)*(2**k))