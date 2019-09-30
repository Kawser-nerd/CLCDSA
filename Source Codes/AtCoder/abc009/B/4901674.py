n=int(input())
a=[int(input()) for i in range(n)]
print(sorted(set(a))[-2])