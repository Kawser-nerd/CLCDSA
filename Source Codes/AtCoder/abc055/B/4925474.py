N=int(input())
def fact(n):
    val=1
    for i in range(2,n+1):
        val*=i
        val%=1000000007
    return val
print(fact(N))