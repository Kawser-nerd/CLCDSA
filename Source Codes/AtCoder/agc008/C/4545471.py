A=list(map(int,input().split()))
ans=A[1]
I,J,L=A[0],A[3],A[4]
odd_cnt=I%2+J%2+L%2
if odd_cnt==0 or odd_cnt==3:
    ans+=I+J+L
elif odd_cnt==1:
    ans+=I+J+L-1
else:
    if I*J*L:
        ans+=I+J+L-1
    else:
        ans+=I+J+L-2
print(ans)