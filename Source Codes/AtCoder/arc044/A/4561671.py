n=int(input())
d=[int(i) for i in str(n)]
if n!=1 and(n==2or n==3 or n==5or(d[-1]%2!=0and d[-1]!=5and sum(d)%3!=0)):
    print("Prime")
else:
    print("Not Prime")