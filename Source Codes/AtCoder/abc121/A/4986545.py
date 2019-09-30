H,W = map(int,input().split())
h,w = map(int,input().split())
print(int((H*W)-(h*W+w*H - h*w)))