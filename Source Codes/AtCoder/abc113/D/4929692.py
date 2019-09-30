H,W,K=map(int,input().split())

dp=[[0 for _ in range(W)] for _ in range(H+1)] #0~H,0~W-1
dp[0][0]=1
P=10**9+7


def check(l):
    for i in range(len(l)-1):
        if l[i+1]+l[i]==2:
            return False
    return True

for i in range(1,H+1):
    for w in range(W):
        X,Y,Z=0,0,0
        for j in range(2**(W-1)):
            tmp=[]
            for k in range(W-1):
                tmp.append(j>>k&1)
            if check(tmp):
                if w-1>=0 and (j>>(w-1))&1==1:
                    X+=1
                elif w<=W-2 and j>>w&1==1:
                    Z+=1
                else:
                    Y+=1
            else:
                continue

        if w-1>=0: dp[i][w-1]=(dp[i][w-1]+dp[i-1][w]*X)%P
        dp[i][w]=(dp[i][w]+dp[i-1][w]*Y)%P
        if w+1<=W-1: dp[i][w+1]=(dp[i][w+1]+dp[i-1][w]*Z)%P

print(dp[H][K-1])