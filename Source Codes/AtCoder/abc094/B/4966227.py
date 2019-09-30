#094 B
N,M,X= map(int,input().split())
A = [int(j) for j in input().split()]
left =0
right = 0

for i in range(1,X):
    if i in A:
        left+=1
for i in range(X+1,N):
    if i in A:
        right+=1
print(min(left,right))