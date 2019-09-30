N = int(input())
a = list(map(int,input().rstrip().split()))
a.sort(reverse=True)
a = a[1:N*2:2]
print(sum(a))