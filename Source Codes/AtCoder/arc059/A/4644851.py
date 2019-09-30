N=int(input())
A=list(map(int,input().split(' ')))
print(min([sum([(a-i)**2 for a in A]) for i in range(min(A),max(A)+1)]))