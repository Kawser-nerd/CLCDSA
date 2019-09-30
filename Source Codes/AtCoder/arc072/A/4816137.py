n = int(input())
A = [int(i) for i in input().split()]

if A[0]>0:
    s = A[0]
    ans1 = 0
else:
    s = 1
    ans1 = -A[0]+1

for i in range(1,n):
    if s*(s+A[i])>=0:
        ans1 += abs(s+A[i])+1
        if s>0:     
            s=-1
        else:
            s=1
    else:   
        s += A[i]
                  
if A[0]<0:        
    s = A[0]
    ans2 = 0
else:
    s = -1
    ans2 = A[0]+1
                    
for i in range(1,n):
    if s*(s+A[i])>=0:
        ans2 += abs(s+A[i])+1
        if s>0:
            s=-1
        else:
            s=1
    else:   
        s += A[i]
print(min(ans1,ans2))