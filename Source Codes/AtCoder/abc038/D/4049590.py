#python script
import bisect
import sys
input = sys.stdin.readline
import numpy

N=int(input())
num_list=[]
h=0
w=0
for j in range(0,N):
    h,w=map(int,input().split())
    num_list.append([h,w])
num_list=sorted(num_list, key=lambda x: x[1],reverse=True)
num_list=sorted(num_list, key=lambda x: x[0])
num_list=[x[1] for x in num_list]
#print(num_list)
#num_list is ordered according to the height
#start dp
dp=[num_list[0]]
for i in range(1,N):
    #append factor to dp_list
    if(len(dp)==1):
        if(dp[-1]<num_list[i]):
            dp.append(num_list[i])
        elif(dp[-1]>num_list[i]):
            dp[-1]=num_list[i]
    else:
        #addition of dp_list
        if(dp[-1]<num_list[i]):
            dp.append(num_list[i])
        #exchange of dp_list
        #basically candidate of the exchange is dp[-1]
        elif(dp[-1]>num_list[i]):
            index=bisect.bisect_left(dp,num_list[i])
            dp[index]=num_list[i]
print(str(len(dp))+"\n")