n,k,x,y = [int(input()) for i in range(4)]
ans = min(k,n)*x+max(0,n-k)*y
print(ans)