# coding: utf-8
# Your code here!

D,G = map(int,input().split()) # D???,G???
lst = [list(map(int,input().split()))for i in range(D)]
ans = float('inf')
for i in range(1 << D): # ???
    tmp = 0
    count = 0
    bit = ""
    for j in range(len(lst)):
        bit+=str((i >> j)&1)
        if ((i >> j) & 1) == 1:
            tmp = tmp + lst[j][1] + ((j + 1) * 100 * lst[j][0])
            count+=lst[j][0]
    #print("tmp",tmp)
    if tmp < G : #or tmp >= G
        #print(bit)
        for n,k in enumerate(list(bit)):
            if k == "0":
                for p in range(lst[len(bit) - n - 1][0]):
                    t = p * 100 * (n+1)
                    #print("p",p,t,tmp,G,count)
                    if t + tmp >= G:
                        ans = min(ans,p+count)
    
    #if tmp >= G :
    else:
        ans = min(ans,count)
    #print(ans,tmp,count)
print(int(ans))