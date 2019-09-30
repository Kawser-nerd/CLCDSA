num = list(map(int, input().split()))
K = int(input())

num.sort()
print(num[0] +num[1] +num[2]*(2**K))