n = int(input())
l = [int(input()) for _ in range(n)]
a = sum(l)
print(a)
print(max(max(l)*2-sum(l),0))