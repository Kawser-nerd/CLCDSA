from itertools import accumulate
n = int(input())
rh = [list(map(int,input().split())) for i in range(n)]
acm = [0]*(10**5+1)
vec = [[0]*3 for i in range(10**5+1)]
for i in range(n):
    num =rh[i][0]
    
    acm[num]+=1
    if rh[i][1]==1:
        vec[num][0] += 1
    elif rh[i][1]==2:
        vec[num][1] += 1
    elif rh[i][1]==3:
        vec[num][2] += 1
lacm =list(accumulate(acm))
for i in range(n):
    num = rh[i][0]
    K = lacm[num-1]
    A = vec[num][0];B = vec[num][1];C = vec[num][2]
    if rh[i][1]==1:
        print(K+B,n-K-A-B,A-1)
    elif rh[i][1]==2:
        print(K+C,n-K-B-C,B-1)
    elif rh[i][1]==3:
        print(K+A,n-K-C-A,C-1)