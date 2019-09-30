X = int(input())
sum_time = 0
for i in range(X):
    sum_time+=(i+1)
    if sum_time>=X:
        print(i+1)
        break