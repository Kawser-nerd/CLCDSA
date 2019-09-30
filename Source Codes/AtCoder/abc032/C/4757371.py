N,K=map(int,input().split())
s = [int(input()) for i in range(N)]
# print(s)
# N = 6
# K = 9
# s = [4, 3, 1, 1, 2, 10, 2]
# s = [10,10,10,10,0,10]
# s = [10,10,10,10,10,10]
# s = [1,2,3,4]
right = 0
res = 0
sum = 1
if 0 in s:
    res = N
else:

    for left in range(0,N):

    # print(left,right,sum)
    #????????right???????
        while(right < N and sum*s[right] <= K):
            sum *= s[right]
            right += 1
        # print(right)
        res = max(res,right-left) 
        if (right == left):
            right += 1
        else:
            sum //= s[left]



print(res)