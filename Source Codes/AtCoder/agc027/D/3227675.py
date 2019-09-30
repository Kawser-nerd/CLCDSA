N = int(input())
xzero = 3
yzero = 5
y = N+1

biggest = 8*(int(N/4)+1)*(int(N/4)+1)+4
a = [[0 for i in range(N+4)] for j in range(N+4)]
fours = [4*i for i in range((int(N/4)+1))]
odds = [2*i for i in range(int((N+1)/2))]
evens = [2*i+1 for i in range(int(N/2))]

if N==2:
    print("4 7")
    print("23 10")
else:
    x = xzero
    for i in fours:
        for j in fours:
            a[i][j] = x
            a[i+1][j+1] = 2*x
            a[i][j+2]=biggest-x
            a[i+1][j+3] = 2*(biggest-x)
            a[i+2][j] = biggest-x-(int(N/4)+1)*2
            a[i+3][j+1] = 2*(biggest-x-(int(N/4)+1)*2)
            a[i+2][j+2] = x+(int(N/4)+1)*2
            a[i+3][j+3] = 2*(x+(int(N/4)+1)*2)
            x += 2
        x+=(int(N/4)+1)*2

    for i in odds:
        for j in evens:
            ans = 1
            ans *= a[i][j - 1]
            ans *= a[i][j + 1]
            if i > 0:
                ans *= a[i - 1][j]
            else:
                ans *= 2
            ans += 1
            a[i][j] = ans

    for i in evens:
        for j in odds:
            ans = 1
            ans *= a[i - 1][j]
            ans *= a[i + 1][j]
            if j > 0:
                ans *= a[i][j - 1]
            else:
                ans *= 2
            ans += 1
            a[i][j] = ans
    a = [i[0:N] for i in a[0:N]]

    for i in range(N):
        print(" ".join(str(j) for j in a[i]))