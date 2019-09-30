I=lambda:list(map(int,input().split()));r,c,d=I();a=0
for i in range(r):j=max(d-i,-1);a=max([a]+I()[j%2:j+1:2])
print(a)