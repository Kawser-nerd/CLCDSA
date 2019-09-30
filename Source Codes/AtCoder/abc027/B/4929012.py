N = int(input())
A = list(map(int, input().split()))


if sum(A)%len(A) !=0:
    print(-1)
    quit()

x = sum(A)/len(A)
ans = 0
for i in range(N-1):
    if (i+1)*x != sum(A[:i+1]):
        ans += 1

print(ans)