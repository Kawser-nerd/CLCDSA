a,b=map(int,input().split())
if 0<a:
    print("Positive")
elif 0<=b:
    print("Zero")
else:
    if abs(a-b)%2==0:
        print("Negative")
    else:
        print("Positive")