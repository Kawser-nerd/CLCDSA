n = int(input())
lis = list(map(int,input().split()))
lis.sort()
if n % 2 == 1:
    if lis[0] != 0:
        print("0")
        exit()
    else:key = 0
else:key = -1
for i in range(n//2):
    if lis[i*2+key+1] != lis[i*2+key+2] or lis[i*2+key+2] != 2*(i+1) + key:
        print("0")
        exit()
ans = 1
for i in range(n//2):
    ans *= 2
    ans %= 10 ** 9 +7
print(ans)