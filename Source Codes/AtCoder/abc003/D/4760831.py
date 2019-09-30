R,C=map(int,input().split())
X,Y=map(int,input().split())
D,L=map(int,input().split())
md=1000000007

def combi(n,k):
    if n<=0 or n<k:
        return 0
    upper=[1,1]
    for stratum in range(2,n+1):
        combination=[1]
        for i,j in zip(upper[:-1],upper[1:]):
            combination.append((i+j)%md)
        combination.append(1)
        upper=[c for c in combination]
    return upper[k]

stuff=D+L
whole=combi(X*Y,stuff)
ud_1=combi(X*(Y-1),stuff)*2
rl_1=combi((X-1)*Y,stuff)*2
ud_2=combi(X*(Y-2),stuff)
rl_2=combi((X-2)*Y,stuff)
ru_2=combi((X-1)*(Y-1),stuff)*4
ud_3=combi((X-1)*(Y-2),stuff)*2
rl_3=combi((X-2)*(Y-1),stuff)*2
rlud_4=combi((X-2)*(Y-2),stuff) if X*Y!=1 else 0
whole=whole-(ud_1+rl_1)+(ud_2+rl_2+ru_2)-(ud_3+rl_3)+rlud_4

pos=(R-X+1)*(C-Y+1)
ans=pos*whole*combi(D+L,D)
print(ans%md)