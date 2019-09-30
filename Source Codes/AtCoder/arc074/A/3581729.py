H,W = list(map(int,input().split()))

min_score = 10**27

for i in range(1,H):
    if W%2==0:
        S1 = i*W/2
        S2 = (H-i)*W
        min_score = min(abs(S1-S2),min_score)
    else:
        S1 = i*(W-1)/2
        S2 = i*(W+1)/2
        S3 = (H-i)*W
        S4 = max(S1,S2,S3)
        S5 = min(S1,S2,S3)
        min_score = min(S4-S5,min_score)

for i in range(1,W):
    if H%2==0:
        S1 = i*H/2
        S2 = (W-i)*H
        min_score = min(abs(S1-S2),min_score)
    else:
        S1 = i*(H-1)/2
        S2 = i*(H+1)/2
        S3 = (W-i)*H
        S4 = max(S1,S2,S3)
        S5 = min(S1,S2,S3)
        min_score = min(S4-S5,min_score)

s1=int(H/3)
s2=int((H-s1)/2)
s3=H-s1-s2
S1 = max(s1*W,s2*W,s3*W)
S2 = min(s1*W,s2*W,s3*W)
min_score = min(S1-S2,min_score)

s1=int(W/3)
s2=int((W-s1)/2)
s3=W-s1-s2
S1 = max(s1*H,s2*H,s3*H)
S2 = min(s1*H,s2*H,s3*H)
min_score = min(S1-S2,min_score)

print(int(min_score))