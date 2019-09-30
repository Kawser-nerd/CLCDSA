def base10to(n, b):
    if (int(n/b)):
        return base10to(int(n/b), b) + str(n % b)
    return str(n % b)


N = int(input())
f = []
for i in range(N):
    f.append(list(map(int, input().split())))
p = []
for i in range(N):
    p.append(list(map(int, input().split())))
ans = []
for i in range(1,1024):
    lis = list(base10to(i, 4).zfill(5))
    temp = 0
    for k in range(N):
        count = 0
        for j in range(len(lis)):
            if lis[j] == '0':
                count += f[k][2*j]*0 + f[k][2*j + 1]*0
            elif lis[j] == '1':
                count += f[k][2*j]*1 + f[k][2*j + 1]*0
            elif lis[j] == '2':
                count += f[k][2*j]*0 + f[k][2*j + 1]*1
            elif lis[j] == '3':
                count += f[k][2*j]*1 + f[k][2*j + 1]*1
        temp += p[k][count]
    ans.append(temp)
print(max(ans))