N = int(input())
A = list(map(int, input().split()))

Flavor = [0 for i in range(max(A) + 1)]
ans    = 1
right  = 0

for left in range(N):
	#????????????
    while right < N and Flavor[A[right]] == 0:
        Flavor[A[right]] += 1
        right += 1
    #???
    ans = max(ans, right - left)

    #????
    if left == right:
        right += 1
    #Flavor??
    else:
        Flavor[A[left]] -= 1

print(ans)