w=list(input())
w_dct={}
for i in w:
    if i in w_dct.keys():
        w_dct[i]+=1
    else:
        w_dct[i]=1
        
tag=True
for i, j in w_dct.items():
    if j%2 ==0:
        pass
    else:
        tag=False
        
if tag:
    print('Yes')
else:
    print('No')