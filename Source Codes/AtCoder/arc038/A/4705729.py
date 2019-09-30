n = int(input())
b = list(map(int,input().split()))
a = sorted(b,reverse = True)
print(sum(a[0:n:2]))