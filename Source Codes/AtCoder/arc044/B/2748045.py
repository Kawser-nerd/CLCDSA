def powmod(a,b,P):
    """(a^b)%P"""
    if b == 0:
        return 1
    stk = []
    while b>1:
        stk.append(b%2)
        b //= 2
    c = a%P
    while len(stk)>0:
        t = stk.pop()
        c = (c*c)%P
        if t == 1:
            c = (c*a)%P
    return c

N = int(input())
A = list(map(int,input().split()))

P = 10**9+7

def count(A):
    S = [0 for _ in range(max(A)+1)]
    for a in A:
        S[a]+=1
    if A[0] != 0 or S[0] != 1:
        return 0
    cnt = 1
    for i in range(1,len(S)):
        if S[i]==0: return 0
        path1 = powmod((powmod(2,S[i-1],P)-1)%P,S[i],P)
        path2 = powmod(2,S[i]*(S[i]-1)//2,P)%P 
        cnt = cnt*path1*path2%P
    return cnt

print(count(A))