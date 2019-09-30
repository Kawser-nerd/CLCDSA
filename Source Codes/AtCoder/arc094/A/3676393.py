x = list(map(int, input().split()))
x.sort()
a,b,c = x
if (b-a)%2 == 0:
    ans = (b-a)//2 + c-b
else:
    ans = (b-a)//2 + 1 + (c+1-b)
print(ans)