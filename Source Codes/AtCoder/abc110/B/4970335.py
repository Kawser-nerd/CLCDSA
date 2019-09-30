N, M, X, Y = map(int, input().split())
x_list = list(map(int, input().split()))
y_list = list(map(int, input().split()))
max_x = max(x_list)
min_y = min(y_list)
for i in range(max_x + 1, min_y + 1):
    if (X < i and i <= Y):
        print("No War")
        exit()
print("War")