import bisect

N, K = map(int, input().split())
A = sorted(list(map(int, input().split())))

data = []
i = 0

while i < len(A):
    x = A[i]
    a = bisect.bisect_left(A, x)
    b = bisect.bisect_right(A, x)
    data.append([x, b - a])
    i = b
    
data = sorted(data, key = lambda x: x[1])
m = len(data) - K
ans = 0

for i in range(0, m):
    ans += data[i][1]
    
print(ans)