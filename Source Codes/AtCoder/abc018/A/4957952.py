A=list(int(input())for i in range(3))
a=A[0]
b=A[1]
c=A[2]
ans=[0]*3
A.sort(reverse=True)
for i in range(3):
    if a==A[i]:
        ans[0]=i+1
    elif b==A[i]:
        ans[1]=i+1
    elif c==A[i]:
        ans[2]=i+1
for i in ans:
    print(i)