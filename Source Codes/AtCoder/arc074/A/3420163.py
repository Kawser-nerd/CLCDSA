# -*- coding: utf-8 -*-
H,W = map(int, input().split())

ret = 10**9
for h in range(1,H):
    w = W//2
    s1 = h*W
    s2 = (H-h)*w
    s3 = (H-h)*(W-w)
    ret = min(ret, max(s1,s2,s3)-min(s1,s2,s3))

    hh = (H-h)//2
    s1 = h*W
    s2 = hh*W
    s3 = (H-h-hh)*W
    ret = min(ret, max(s1,s2,s3)-min(s1,s2,s3))

for w in range(1,W):
    h = H//2
    s1 = w*H
    s2 = (W-w)*h
    s3 = (W-w)*(H-h)
    ret = min(ret, max(s1,s2,s3)-min(s1,s2,s3))

    ww = (W-w)//2
    s1 = w*H
    s2 = ww*H
    s3 = (W-w-ww)*H
    ret = min(ret, max(s1,s2,s3)-min(s1,s2,s3))

print(ret)