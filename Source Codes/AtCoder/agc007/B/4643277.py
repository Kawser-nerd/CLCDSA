N=int(input())

p = list(map(int,input().split()))
q = [0 for i in range(N)]
for i in range(N):
    q[p[i]-1]=i
    
A = 0
B = 10**9+1
ans_a = []
ans_b = []
for i in range(N):
    A+=q[i]
    if i!=0:
        B-=q[i-1]
    A+=1
    B-=1
    ans_a.append(A)
    ans_b.append(B)
    
print(*ans_a)
print(*ans_b)