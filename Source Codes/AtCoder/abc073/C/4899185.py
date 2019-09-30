from collections import Counter
N=int(input())
A=[]
for i in range(N):
    A.append(int(input()))

a=Counter(A)
count=0
#for i in values
for i in a.values():
    if i%2!=0:
        count+=1
#    print(i)
print(count)