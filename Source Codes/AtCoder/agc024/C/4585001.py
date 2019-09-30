N = int(input())
l =[]
#deal with error
for i in range(N):
    l.append(int(input()))
    if i == 0 and l[i]!=0:
        print(-1)
        exit()
    if i>=1:
        if l[i]-l[i-1]>1 :
            print(-1)
            exit()
 
ans = 0
pre = -1
for a in l[::-1]:
    if pre - 1 != a:
        ans += a
    pre = a
print(ans)