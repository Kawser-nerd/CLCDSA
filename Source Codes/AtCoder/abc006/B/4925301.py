n = int(input())
a = [0,0,1]
for i in range(3,n):
    a.append(sum(a[i-3:i])%10007)
print(a[n-1])