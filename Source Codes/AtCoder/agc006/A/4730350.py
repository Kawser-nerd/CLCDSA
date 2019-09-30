n=int(input())
s=input()
t=input()
l=0
m=max([i for i in range(n+1)if s[-i:]==t[:i]]or[0])
print(2*n-m)