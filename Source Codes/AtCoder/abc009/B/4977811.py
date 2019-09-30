n=int(input())
a=[int(input()) for i in range(n)]
print(sorted(list(set(a)))[-2])