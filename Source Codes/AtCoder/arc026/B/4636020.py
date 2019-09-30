n=int(input())
a=-n
for i in range(1,int(n**0.5)+1):
    if n%i==0:
        a+=i+(n//i)
if n==int(n**0.5)**2:
    a-=int(n**0.5)
print("Perfect" if n==a else("Deficient" if n>a else"Abundant"))