x,y,c=list(map(int, input().split()))
judge=0
if x+y==c:
    judge +=2
if x-y==c:
    judge -=1
if judge==2:
    print("+")
elif judge==-1:
    print("-")
elif judge==1:
    print("?")
elif judge==0:
    print("!")