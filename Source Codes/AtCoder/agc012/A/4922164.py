n=int(input())
a=sorted([int(i) for i in input().split()],reverse=True)
x=[a[i] for i in range(1,n*2,2)]
print(sum(x))