N = int(input())
A = list(map(int,input().split()))

maxlength = 0
right = 0
Checklist = [False] * 100001

for left in range(N):
    while right < N and not Checklist[A[right]]:
        Checklist[A[right]] = True
        right += 1
    maxlength = max(maxlength, right - left)
    Checklist[A[left]] = False
print(maxlength)