N,L=map(int,input().split())
N=[0]*N
for i in range(len(N)):
    N[i]=input()
N_s=sorted(N)
print(''.join(N_s))