N = int(input())
ans = 0
 
for i in range(1, len(str(N)) + 1):
    ans += (N // (10 ** i)) * (10 ** (i - 1))
 
    b = N % (10 ** i)
    if b:
        if b >= 2 * 10 ** (i - 1):
            ans += 10 ** (i - 1)
        elif b >= 10 ** (i - 1):
            ans += b % (10 ** (i - 1)) + 1
 
print(ans)