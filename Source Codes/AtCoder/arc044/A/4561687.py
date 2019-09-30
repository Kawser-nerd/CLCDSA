n=int(input())
if n!=1 and(n==2or n==3 or n==5or(n%2!=0 and n%3!=0 and n%5!=0)):
    print("Prime")
else:
    print("Not Prime")