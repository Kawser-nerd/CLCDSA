a = int(input())
x = list(map(int,input().split()))
t = range(1,a+1)
A = []
B = []
for i in range(1,a+1):
    A.append(30000*i)
    B.append(30000*(a-i+1))
for i ,d in enumerate(x):
    A[d-1] -= a-i
print(*A)
print(*B)