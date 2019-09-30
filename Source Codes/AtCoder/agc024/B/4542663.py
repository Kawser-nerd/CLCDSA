import sys
input = sys.stdin.readline

N=int(input())
A=[int(input())-1 for i in range(N)]
Q=[0]*N
for i in range(N):
    Q[A[i]]= i
#print(Q)
num=0
s=1
t=Q[0]
for i in range(1,N):
    if t>Q[i]:
        num=max(s,num)
        s=0
    s+=1
    t=Q[i]
    #print(s)
num=max(s,num)
print(N-num)