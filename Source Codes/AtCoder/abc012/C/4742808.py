n=int(input())
a=2025-n
l=[]
for i in range(1,10):
    if a%i==0:
        if a/i<10:
            l+=[a/i]
for j in l:
    print(str(round(a/j))+' x '+str(round(j)))