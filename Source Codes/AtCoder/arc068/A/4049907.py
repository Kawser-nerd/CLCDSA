x = int(input())
ans = x//11*2
x %= 11
if x == 0:
    print(ans)
elif x <= 6:
    print(ans+1)
else:
    print(ans+2)