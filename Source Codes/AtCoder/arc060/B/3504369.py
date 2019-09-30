def digitsum(n,b):
    if n < b:
        return n
    else:
        return digitsum(n//b,b) + n%b 

n = int(input())
s = int(input())
inf = float('inf')
ans = inf

for i in range(2,int(n**(1/2))+2):
    if digitsum(n,i) == s:
        ans = i
        break
if n == s:
    ans = n+1
else:
    for i in range(1,int(n**(1/2))):
        if i*i-i >= n-s:
            break
        if (n-s) % i == 0:
            if s-i >= (n-s)//i +1 or i > s:
                continue
            ans = min(ans,((n-s)//i)+1)
            
if ans == inf:
    print(-1)
else:
    print(int(ans))