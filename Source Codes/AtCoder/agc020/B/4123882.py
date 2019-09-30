K = int( input())
A = list( map( int, input().split()))
nowm = 2
nowM = 2
ans = 0
for i in range(K-1,-1,-1):
    a = A[i]
    if nowm <= ((nowm+a-1)//a)*a and ((nowm+a-1)//a)*a <= nowM:
        nowm = ((nowm+a-1)//a)*a
        nowM = (nowM//a)*a + a - 1
    else:
        ans = -1
        break
    # if nowM < A[i]:
    #     ans = -1
    #     break
    # elif nowm <= A[i]:
    #     nowm = A[i]
    #     nowM = A[i]*2 - 1
    # else:
    #     M = nowM
    #     nowm = (nowm//A[i]+1)*A[i]
    #     if nowm > M:
    #         ans = -1
    #         break
    #     if (nowM//A[i]+1)*A[i] <= M:
    #         nowM = (nowM//A[i]+1)*A[i] - 1
    #         if nowM < nowm:
    #             nowM = nowm + A[i] - 1
    #     else:
    #         nowM = nowm + A[i] - 1
if ans == -1:
    print( -1)
else:
    print("{} {}".format(nowm, nowM))