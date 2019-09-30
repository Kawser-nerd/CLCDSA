N,Q=map(int,input().split())
S=input()
AC=[0]*N
AC_cnt=0
for i in range(1,N):
    if S[i-1]=='A' and S[i]=='C':
        AC_cnt+=1
    AC[i]=AC_cnt
for _ in range(Q):
    l,r=map(int,input().split())
    ans=AC[r-1]-AC[l-1]
    print(ans)