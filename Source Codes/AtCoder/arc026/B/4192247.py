n=int(input())

num=1

if n==1:
    print("Deficient")
    exit()
else:
    for i in range(2,10**6):
        if i*i>n:
            break
        elif n%i==0:
                num+=i
                if i!=(n//i):
                    num+=(n//i)
if num>n:
    print("Abundant")
elif num==n:
    print("Perfect")
else:
    print("Deficient")