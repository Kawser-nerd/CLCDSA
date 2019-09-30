x,y=map(int,input().split())
print(min(i for i in [y-x,y+x+1,-y+x+2,-y-x+1] if i>=0))