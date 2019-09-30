m,n,N =[int(i) for i in input().split()]
ans =N
while N >= m:
    ans += N//m*n
    N = N%m +N//m*n
print(ans)