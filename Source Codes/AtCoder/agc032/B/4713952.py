n=int(input())
for a in[[n*~-n//2-n//2]]+[(i,j)*(j>i!=n-j+1-n%2)for i in range(1,n)for j in range(n+1)]:print(*a)