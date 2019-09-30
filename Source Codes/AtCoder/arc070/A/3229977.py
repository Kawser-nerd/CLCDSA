X=abs(int(input()))
n=0
while True:
    if n*(n+1)/2>=X:
        ans=n
        break
    n+=1
print(ans)