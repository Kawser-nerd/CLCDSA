n=int(input());print(*[~-n*~-n//2]+['%d %d'%(i,j)*(j>i!=n-j+1-n%2)for i in range(1,n)for j in range(n+1)])