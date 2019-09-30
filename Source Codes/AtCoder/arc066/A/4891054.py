N=int(input())
A=sorted(list(map(int,input().split(' '))))
if N%2==1:
	B=[ ((i+1)//2)*2 for i in range(N) ]
	C=[ 0 if A[i]==B[i] else 1 for i in range(N) ]
	flag=True if sum(C)==0 else False
elif N%2==0:
	B=[ (i//2)*2+1 for i in range(N) ]
	C=[ 0 if A[i]==B[i] else 1 for i in range(N) ]
	flag=True if sum(C)==0 else False
print((2**(N//2))%(10**9+7)) if flag else print(0)