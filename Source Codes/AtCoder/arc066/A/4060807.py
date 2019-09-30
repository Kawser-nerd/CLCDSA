n = int(input())
a = list(int(i) for i in input().split())
if n%2==0 and sum(a)==n*n//2 or n%2==1 and sum(a) == (n+1)*(n//2):
    print(2**(n//2)%(10**9+7))
else:
    print(0)