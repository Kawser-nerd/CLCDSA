n,k,x,y=[int(input()) for i in range(4)]
print(x*min(n,k)+y*max(n-k,0))