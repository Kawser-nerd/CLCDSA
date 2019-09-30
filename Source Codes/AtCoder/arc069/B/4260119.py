n = int(input())
s=list(input())



def f(k):
    if s[k] == 'o' and a[k] == 1:
        a[k+1] = a[k-1]
    elif s[k] == 'o' and a[k] == -1:
        a[k+1] = a[k-1]*(-1)
    elif s[k] == 'x' and a[k] == 1:
        a[k+1] = a[k-1]*(-1)
    else:
        a[k+1] = a[k-1]
judge = -1
for e in [[1,1],[1,-1],[-1,1],[-1,-1]]:
    if judge == -1:
        a = [0]*n
        a[0] = e[0]
        a[1] = e[1]
        for j in range(1,n-1):
            f(j)
        if s[0] == 'o' and a[0] == 1:
            if a[1] ==  a[-1]:
                judge = 1
        elif s[0] == 'o' and a[0] == -1:
            if a[1] == a[-1]*(-1):
                judge = 1
        elif s[0] == 'x' and a[0] == 1:
            if a[+1] == a[-1]*(-1):
                judge = 1
        else:
            if a[1] == a[-1]:
                judge = 1
        if judge == 1:
            if s[n-1] == 'o' and a[n-1] == 1:
                if a[0] != a[n-2]:
                    judge = -1
            elif s[n-1] == 'o' and a[n-1] == -1:
                if a[0] != a[n-2]*(-1):
                    judge = -1
            elif s[n-1] == 'x' and a[n-1] == 1:
                if a[0] != a[n-2]*(-1):
                    judge = -1
            else:
                if a[0] != a[n-2]:
                    judge = -1
if judge == -1:
    print(-1)
else:
    ans = ''
    for i in range(n):
        if a[i] == 1:
            ans += 'S'
        else:
            ans += 'W'
    print(ans)