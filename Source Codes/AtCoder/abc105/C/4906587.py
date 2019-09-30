import sys
N=int(input())

if N==0: print(0),sys.exit()

ans=""
dic=["00","01","10","11"]
a=[0,1,-2,-1]

while N!=0:
    i=N%4
    ans=dic[i]+ans
    N-=a[i]
    N//=4
print(ans if ans[0]=="1" else ans[1:])