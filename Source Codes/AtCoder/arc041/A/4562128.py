x,y=map(int,input().split())
k=int(input())
print(min(y,k)+x-max(k-y,0))