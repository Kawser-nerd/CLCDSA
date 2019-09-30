import numpy as np

N, T = np.array(input().split(), dtype="int")
A = np.array(input().split(), dtype="int")

max_num=A[-1]
num_dict = {}
for i in range(len(A)-1):
    ##print(A[-i-1],max_num - A[-i-2],num_dict)
    if(A[-i-1]>max_num):
        max_num=A[-i-1]
    if(max_num > A[-i-2]):
        if(max_num - A[-i-2] in num_dict):
            num_dict[max_num - A[-i-2]] +=1
        else:
            num_dict[max_num - A[-i-2]]=1
key = max(num_dict.keys())
print(num_dict[key])