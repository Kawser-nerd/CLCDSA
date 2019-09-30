N = int(input())
a = [int(i) for i in input().split()]
ans = 0
 
if sum(a) % N != 0:
    print(-1)
    quit()
 
for i in range(N-1):
    if sum(a[:i+1]) != (i+1) * sum(a) / N:
        ans += 1
 
print(ans)