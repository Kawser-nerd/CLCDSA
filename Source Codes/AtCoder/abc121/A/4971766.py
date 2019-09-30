# coding:utf-8
H, W = map(int, input().split())
h, w = map(int,input().split())

ans = H*W - (h*W + w*(H-h))
print(ans)