X=int(input())
ans = 1
for i in range(2,int(X**0.5)+1):
    for p in range(2,11):
        if i**p > X:
            ans = max(ans,i**(p-1))
            break
print(ans)