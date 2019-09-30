#!/mnt/c/Users/moiki/bash/env/bin/python
N = int(input())
A = list(map(int, input().split()))


tmpxor = 0
tmpadd = 0
ans = 0
minindex = 0
maxindex = 0
for e,i in enumerate(A):
    tmpadd += i
    tmpxor ^= i
    maxindex = e
    if tmpxor != tmpadd:
        while tmpxor != tmpadd and minindex < e:
            tmpxor ^= A[minindex]
            tmpadd -= A[minindex]
            minindex += 1
            # ans += 1
    ans += maxindex - minindex + 1


        # if tmpxor != tmpadd:
        #     maxindex -= 1
    # ans += maxindex - minindex + 1
print(ans)