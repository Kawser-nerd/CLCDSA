#094
A,B,K= map(int,input().split())
ans=[]
for i in range(K):
    if A+i <=B:
        
        ans.append(A+i)
for i in range(K):
    if B-i >=A:
        
        ans.append(B-i)
ans =list(set(ans))
ans.sort()
for i in ans:
    print(i)