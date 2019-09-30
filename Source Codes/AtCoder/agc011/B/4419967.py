n = int(input())
a = sorted(map(int,input().split()))
ruiseki = [0]
for i in range(n):
    ruiseki.append(ruiseki[-1]+a[i])
ruiseki = ruiseki[1:]

ans = 0
for i in range(n)[::-1]:
    eater = ruiseki[i]
    if i==n-1 or eater*2 >= a[i+1]:
        ans +=1
    else:
        break
print(ans)