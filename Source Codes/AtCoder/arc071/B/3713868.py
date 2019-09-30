def count_func(m,k):
    return k*(m-k+1)

N,M = list(map(int,input().split()))
x = list(map(int,input().split()))
y = list(map(int,input().split()))

x.sort()
y.sort()

x_line_sum = 0
y_line_sum = 0

for i in range(N-1):
    x_line_sum += (count_func(N-1,min(i+1,N-1-i)) * (x[i+1]-x[i]))%(10**9 + 7)

for i in range(M-1):
    y_line_sum += (count_func(M-1,min(i+1,M-1-i)) * (y[i+1]-y[i]))%(10**9 + 7)
 
print((x_line_sum*y_line_sum)%(10**9 + 7))