N=int(input())

min_=100000

for i in range(1, N//2+1):
    j=N-i
    sum_i=0
    sum_j=0
    tmp_i=i
    tmp_j=j
    while tmp_i  > 0:
        sum_i += tmp_i % 10
        tmp_i = tmp_i // 10
    while tmp_j > 0:
        sum_j += tmp_j % 10
        tmp_j = tmp_j // 10
    min_=min(min_, sum_i+sum_j)

print(min_)