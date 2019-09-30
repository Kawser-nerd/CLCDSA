N,A,B = map(int,input().split())
if not (A+B-1 <= N <= A*B):
    print(-1)
    exit()
if B == 1:
    print(*list(range(1,A+1)))
    exit()

n = (N-A)//(B-1)
m = (N-A)%(B-1)

stack = [1,A+1]
lds_cnt = 1
while stack[-1] <= N:
    l = n if lds_cnt > m else n+1
    stack.append(stack[-1] + l)
    lds_cnt += 1

ans = []
while len(stack) > 1:
    ans += list(range(stack[-2], stack[-1]))
    stack.pop()
print(*ans)