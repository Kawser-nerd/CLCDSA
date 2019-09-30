H,W=list(map(int,input().split()))
h,w=list(map(int,input().split()))

print(H*W-(h*W+w*(H-h)))