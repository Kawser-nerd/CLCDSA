a,b = map(int,input().split())               

if a<=0 and 0<=b:
    print("Zero")
elif 0<a:
    print("Positive")
elif (b-a+1)%2:
    print("Negative")
else:
    print("Positive")