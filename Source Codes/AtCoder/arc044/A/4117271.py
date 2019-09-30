N=int(input())
flag=1
if N==1:flag=0
elif N==2 or N==3 or N==5:flag=1
elif N%2==0 or N%3==0 or N%5==0:flag=0
else:flag=1
print("Prime" if flag==1 else "Not Prime")