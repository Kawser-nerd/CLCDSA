li = [int(x) for x in input().split()]
K = int(input())
a = max(li)
print(sum(li)-a+a*(2**K))