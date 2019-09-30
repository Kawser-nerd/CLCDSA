n=int(input())
a=[int(input()) for i in range(n)]
print(len(a)-len(set(a)))