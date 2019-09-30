a,b,k,l=map(int,input().split())
print(min([a*k,(k//l)*b+(k%l)*a,(k//l+1)*b]))