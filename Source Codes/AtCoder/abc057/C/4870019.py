N = int(input())
def divisor_all(n): # ?????
    import math as ma
    l = [1,n]
    for i in range(2,int(ma.sqrt(n))+1):
        if n % i == 0:
            l.append(i)
            l.append(n//i)
    l.sort()
    return l
ans = float('inf')
m = divisor_all(N)
for i in m:
    j = N // i
    ans = min(ans,max(len(str(i)),len(str(j))))
print(ans)