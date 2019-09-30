N=int(input())
a=list(map(int, input().split()))


right = 0
res = 0
for left in range(0,N):
    #????????right???????

    while(right < N and ((a[right-1]<a[right])or(left >= right))):
        right += 1
    res += right-left
    if (right == left):
        res+=1

print(res)