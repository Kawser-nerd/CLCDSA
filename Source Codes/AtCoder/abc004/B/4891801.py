import time
import math
list=[]
for a in range(4):
    list.append(input().split())
for a in range(len(list)):
    string=""
    for b in range(len(list[0])):
        if b==len(list[0])-1:
            string+=list[len(list)-a-1][len(list)-b-1]
        else:
            string+=list[len(list)-a-1][len(list)-b-1]+" "
    print(string)