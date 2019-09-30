n=int(input())
a=sorted(set([int(input()) for __ in range(n)]),reverse=True)
print(a[1])