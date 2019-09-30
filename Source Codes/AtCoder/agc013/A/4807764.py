N = int(input())
A = list(map(int, input().split()))
#greedy???
upflag = True
downflag = True
answer = 1
for i in range(N - 1):
    if A[i] < A[i + 1]:
        downflag = False
    if A[i] > A[i + 1]:
        upflag = False
    if not (upflag or downflag):
        answer += 1
        upflag = True
        downflag = True
print(answer)