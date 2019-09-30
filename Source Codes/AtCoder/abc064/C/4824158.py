N = int(input())
R = list(map(int,input().split()))
a = [0]*8
b = 0
for i in range(N):
    if R[i] < 400:
        a[0] += 1
    elif R[i] < 800:
        a[1] += 1
    elif R[i] < 1200:
        a[2] += 1
    elif R[i] < 1600:
        a[3] += 1
    elif R[i] < 2000:
        a[4] += 1
    elif R[i] < 2400:
        a[5] += 1
    elif R[i] < 2800:
        a[6] += 1
    elif R[i] < 3200:
        a[7] += 1
    else:
        b += 1
ans = 0
for i in range(8):
    if a[i] != 0:
        ans += 1
ans2 =str(ans+b)
if ans == 0:
    ans = 1
ans1 = str(ans)
print(ans1+" "+ans2)