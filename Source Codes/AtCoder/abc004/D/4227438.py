R,G,B=map(int,input().split())
ans=[0 for _ in range(1000)]

def countup(Left,Right,offset):
    Left=Left-offset
    Right=Right-offset

    if Right<0:
        Left=-1*Left
        Right=-1*Right
        return (Left*(Left+1) - Right*(Right-1))>>1
    elif Left<=0<=Right:
        Left = -1 * Left
        return (Left*(Left+1) + Right*(Right+1))>>1
    else:
        return (Right*(Right+1) - Left*(Left-1))>>1


for g in range(-500,500):
    G_Left=g
    G_Right=g+G-1

    if (((R-1)>>1)-100) < G_Left:
        R_Right = ((R-1)>>1)-100
    else:
        R_Right = G_Left - 1
    R_Left = R_Right - R + 1

    if (100-((B-1)>>1)) > G_Right:
        B_Left = 100-((B-1)>>1)
    else:
        B_Left = G_Right + 1
    B_Right = B_Left + B - 1

    ans[g+500] += countup(G_Left, G_Right, 0)
    ans[g+500] += countup(R_Left, R_Right, -100)
    ans[g+500] += countup(B_Left, B_Right, 100)

print(min(ans))