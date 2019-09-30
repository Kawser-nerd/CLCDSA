import sys,bisect,math
input = sys.stdin.readline

# i ???????? a1~ai?????????( O(log n) )
def bitsum(bit,i):
    s = 0
    while i > 0:
        s += bit[i]
        i -= i&(-i)
    return s
    
# i ? x ???????? ai += x ??? ( O(log n) )
def bitadd(bit,i,x):
    while i <= n:
        bit[i] += x
        i += i&(-i)
    return bit

n,k = map(int,input().split())
a = [int(input()) for i in range(n)]

#b[j+1]-b[i]:a[i]~a[j]
b = [0]
for i in range(n):
    b.append(b[-1]+a[i])

#c[i]:b[i]-k*i
c = [0]*(n+1)
for i in range(n+1):
    c[i] = b[i]-k*i

d = sorted(c)
for i in range(n+1):
    k = bisect.bisect_left(d,c[i])
    d[k] = d[k]-0.1
    c[i] = k+1

n = n+1
n_ = int(math.log2(n)) + 1
bit = [0] * (2**n_+1)
ass = 0
for j in range(n):
    ass += j-bitsum(bit,c[j])
    #bitsum(bit,a[j]): j-1???????a[j]?????
    bit = bitadd(bit,c[j],1)


print(n*(n-1)//2-ass)