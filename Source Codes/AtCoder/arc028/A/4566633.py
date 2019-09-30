n,a,b=map(int,input().split())
n=n%(a+b)
print("Bug"if n==0 or n>a else"Ant")