n=int(input())
a=sorted([int(input()) for i in range(n)])
print(sum(a))
print(max(0,a[-1]-sum(a[:-1])))