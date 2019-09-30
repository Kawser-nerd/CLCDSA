import sys

N,a=map(int,input().split())
k=int(input())
B=list(map(int,input().split()))

LIST=[]
for case in range(N*2):
    LIST.append(a)
    a=B[a-1]

if k<N*2:
    print(LIST[k])
    sys.exit()
    

else:
    x=LIST[-1]
    for y in range(N*2-2,-1,-1):
        if LIST[y]==x:
            break

k=(k-(2*N-1))%(2*N-1-y)

for case in range(k):
    x=B[x-1]

print(x)