def fun():
     print('ac')
     print('ac')
     print('ac')
     print('ac')
N,M=map(int,input().split())
if N*2>=M:
     print(M//2)
else:
     result=N+(M-2*N)//4
     print(result)