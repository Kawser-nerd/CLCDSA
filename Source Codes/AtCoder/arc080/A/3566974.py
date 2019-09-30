N = int(input())
L = list(map(int,input().split()))

p = 0
q = 0
r = 0

for i in range(N) :
    if L[i] % 4 == 0 :
        p += 1
    else :
        if L[i] % 2 == 0 :
            q += 1
        else :
            r += 1

if q == 0 :
    if p >= r-1 :
        ans = "Yes"
    else :
        ans = "No"
else :
    if p >= r :
        ans = "Yes"
    else :
        ans = "No"
        
print(ans)