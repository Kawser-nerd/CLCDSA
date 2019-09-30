N=int(input())
A=list(map(int,input().split()))
H=list(map(int,input().split()))

HH=list(map(lambda x:abs(A[1]-(A[0]-x*0.006)),H))
print(HH.index(min(HH))+1)