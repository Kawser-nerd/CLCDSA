x = int(input())

r = x % 11
if r == 0:
    ans = x//11*2
elif r > 6:
    ans = x//11*2+2
else:
    ans = x//11*2+1
print(ans)