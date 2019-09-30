N = int(input())

ans = 0
k = 1

while k <= N :
    ans += N // (k*10) * k #??????????
    ans += max(0, min(k, N % (k * 10) - k + 1))
    k *= 10
print(ans)