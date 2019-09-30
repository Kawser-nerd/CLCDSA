N=int(input())
l=[]
l_value=[]
i=0
stack=-1
for i in range(N):
    if i < N:
        l.append(input())
list_simple=[]
for i in l:
    if stack != i:
        list_simple.append(i)
    stack = i
dp_dict=[0]*200001
dp=1
for i in list_simple:
    i=int(i)
    dp = dp_dict[i] +dp
    dp_dict[i] = dp
print(dp%(10**9+7))