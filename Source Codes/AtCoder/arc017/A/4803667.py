n=int(input())
for i in range(2,n//2+1):
    if n%i==0:
        print("NO")
        break
else:
    print("YES")