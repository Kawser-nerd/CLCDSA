n = int(input())
a = list(map(int,input().split()))
mx = max(a)
if mx < sum(a)-mx:
    print("Yes")
else:
    print("No")