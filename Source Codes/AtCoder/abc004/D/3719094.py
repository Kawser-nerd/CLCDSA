R,G,B=map(int,input().split())

def rt(i,j):#R=j-i+1
    x=-100-i
    y=-100-j

    if x*y>0:
        return (abs(x)+abs(y))*(abs(x-y)+1)//2
    else:
        return abs(x)*(abs(x)+1)//2+abs(y)*(abs(y)+1)//2


def gt(i,j):
    x=i
    y=j

    if x*y>0:
        return (abs(x)+abs(y))*(abs(x-y)+1)//2
    else:
        return abs(x)*(abs(x)+1)//2+abs(y)*(abs(y)+1)//2

def bt(i,j):
    x=100-i
    y=100-j

    if x*y>0:
        return (abs(x)+abs(y))*(abs(x-y)+1)//2
    else:
        return abs(x)*(abs(x)+1)//2+abs(y)*(abs(y)+1)//2

ANS=10**10

for j in range(-300,51):
    k=max(100-(B-1)//2,j+G)
    i=min(j-1,-100+(R-1)//2)


    if ANS>rt(i+1-R,i)+gt(j,j+G-1)+bt(k,k+B-1):
        ANS=rt(i+1-R,i)+gt(j,j+G-1)+bt(k,k+B-1)
        #print(i,j,k,ANS)


print(ANS)