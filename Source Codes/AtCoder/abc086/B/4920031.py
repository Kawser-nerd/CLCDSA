a,b=input().split()
x=int(a+b)**(1/2)
print("Yes" if x.is_integer() else "No")