n = int(input())
a = [int(input()) for i in range(n)]
b = list(set(a))
print(len(a)-len(b))